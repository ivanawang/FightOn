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

//part 2
class User {

	private:
	string name_;
	int age_;
	List friends;
		
	public: 
		User(){
			name_=" ";
			age_ = -100;
		}
		
		//Returns the name of the user
		string getName(){
			return name_;
		}
		//Set the name of the user
		void setName(string name){
			name_ = name;
		}
		
		//Returns the age of the user
		int getAge(){
			return age_;
		}
		//Sets the age of the user
		void setAge(int age){
			age_ = age;
		}
		
		//adds friend to next spot in array
		void addFriend(string name){
			friends.push_back(name);
		}
		
		//part 4- print user information
		void printInfo(){
			cout<< "Name: " <<name_ <<endl;
			cout<< "Age: " <<age_ <<endl;
			cout<< "Friends: " <<endl;
			friends.printList();
			cout<<endl;
		}
};
