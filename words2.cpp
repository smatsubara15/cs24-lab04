// words1.cpp - implements class Words
// (dynamic  array version)
//Scott Matsubara
//October 27th 2018

#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab04_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
	capacity=initial_capacity;
        data=new string[capacity];
    }
  Words::Words(const Words &source){
    used=source.used;
    capacity=source.capacity;
    data=new string[capacity];
    for (int i=0; i<used; i++){
      data[i]=source.data[i];
    }
  }
    Words::~Words() {
        delete [] data;
    }
    
    void Words::append(string word) {
      if (used >= capacity){
	capacity=used*2;
	std::string *data2;
	data2=new string[capacity];
	for (int i=0; i<used; i++){
	  data2[i]=data[i];
	}
	delete [] data;
	data=data2;
      }
        data[used] = word;
        ++used;
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }
  Words& Words::operator=(const Words &source){
    if (this == &source)
      return *this;
    if (capacity!=source.capacity){
      capacity=source.capacity;
      delete data;
      data=new string[capacity];
    }
    used=source.used;
    for (int i=0; i<used; i++){
      data[i]=source.data[i];
    }
    return *this;
  }
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }
    
}
