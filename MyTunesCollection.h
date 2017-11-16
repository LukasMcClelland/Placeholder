//Ian Denault Student#: 101 057 419
//Lukas McClelland Student#: 101 057 299

/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Authors:  Ian Denault 101 057 419                */
/*            Lukas McClelland 101 057 299			 */
/*  Date:     NOV-2017                               */
/*                                                   */
/*  (c) Nov 2017                                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <ostream>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "UI.h"


using namespace std;
template <typename T>
class MyTunesCollection {
public:
	MyTunesCollection();
	~MyTunesCollection(void);
	T* findByID(int anID);
	T* findByID(const string & aUserID);
	map<int, T*> getCollection();
	void add(T & aElement);
	void remove(T & aElement);
	void showOn(UI& aView);
	void showOn(UI& aView, int memberID);
	void showOn(UI & view, const string & memberID);
private:
	//PART 2 CHANGE: We are using maps instead of vectors for the collection. Reasoning behind this change in ReadMe.
	map<int, T*> collection;

};

template <typename T>
MyTunesCollection<T>::MyTunesCollection(){
	//default constructor
}

template <typename T>
MyTunesCollection<T>::~MyTunesCollection(void){
	//destructor
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Recordings in this container
}

//simple get method
template <typename T>
map<int, T*> MyTunesCollection<T>::getCollection(){return collection;}

//returns a pointer to object T in the collection (pass in int)
template <typename T>
T* MyTunesCollection<T>::findByID(int anID){
//	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
//		if((*it)->getID() == anID) return *it;

	return collection.at(anID);
}

//returns a pointer to an object T in the collection (pass in string)
template <typename T>
T* MyTunesCollection<T>::findByID(const string & aUserID) {
//	for (vector<T>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
//		if(((*itr)->getUserID()).compare(aUserID) == 0) return *itr;

	for (typename map<int, T*>::iterator i = collection.begin(); i != collection.end(); ++i) {
		if(i->second->getUserID() == aUserID){
			return i->second;
		}
	}
	return NULL;
}

//One of the parts of the demo code that we found we could do without
//template <typename T>
//typename vector<T*>::iterator MyTunesCollection<T>::findPosition(T & aElement){
//	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
//		if(*it == &aElement) return it;
//	return collection.end();
//}

//adds the pointer to an element/object to the collection
template <typename T>
void MyTunesCollection<T>::add(T &aElement){
	int temp = aElement.getID();
	collection[temp] = &aElement;
}

//removes the pointer to an element/object to the collection
template <typename T>
void MyTunesCollection<T>::remove(T & aElement){
	int temp = aElement.getID();
	collection.erase(temp);


//	typename vector<T*>::iterator index = findPosition(aElement);
//	if(index != collection.end()) {
//		T * theT = *index;
//		collection.erase(index);
//		delete theT; //free the memory of theRecording
//	}
}

//the following 3 showOn methods are to be used when printing out the objects that are stored in the collection
template <typename T>
void MyTunesCollection<T>::showOn(UI& view){
	view.printOutput("Collection:");
	for (typename map<int, T*>::iterator i = collection.begin(); i != collection.end(); ++i) {
		view.printOutput(i->second->toString());
	}
}
template <typename T>
void MyTunesCollection<T>::showOn(UI& view, int memberID)  {
	T * type = findByID(memberID);
	if( type != NULL)
		view.printOutput(type->toString());
}
template <typename T>
void MyTunesCollection<T>::showOn(UI & view, const string & memberID) {
	view.printOutput("User:");
	T * user = findByID(memberID);
	if( user != NULL)
		view.printOutput(user->toString());
}
//template <typename T>
//ostream& operator<<(ostream& out,  anElement)
//{
//	map<int, T*> collection = anElement.getCollection();
//
//	for (typename map<int, T*>::iterator i = collection.begin(); i != collection.end(); i++){
//		out << i->second->toString();
//	}
//
//	return out;
//}
