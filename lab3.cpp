#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//part 1
class List{
  private:
		int size_; //current size of array
		int cap_; //capacity of array
		string *friends;
		string *temp;
	
	public:		
		//constructor- makes array "friends"
		List() {
			size_= 0;
			cap_= 8;
			friends= new string[cap_];
		}
		
		//pushback method
		void push_back(string name){
			if (size_== cap_) {
				temp = new string[cap_];
				for(int i=0; i<cap_; i++) {
					friends[i] = temp[i];
				}
				
				delete [] friends;
				friends = new string[cap_*2];
				for(int i=0; i<cap_; i++){
					friends[i]=temp[i];
				}
			}
			friends[size_] = name;
			size_++;
		}
		
		//size method
		int size(){
			return size_;
		}
		
		//at method
		string at(int x){
			return friends[x];
		}
		
		//deconstructor
		~List() {
			delete [] friends;
		}
	
};
