/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel                              */
/*  Date:     21-SEP-2017                            */
/*                                                   */
/*  (c) 2017 Louis Nel                               */
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
	map<int, T*> collection;
	typename vector<T*>::iterator findPosition(T& aElement);
};

template <typename T>
MyTunesCollection<T>::MyTunesCollection(){}
template <typename T>
MyTunesCollection<T>::~MyTunesCollection(void){
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Recordings in this container
}
template <typename T>
map<int, T*> MyTunesCollection<T>::getCollection(){return collection;}

template <typename T>
T* MyTunesCollection<T>::findByID(int anID){
//	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
//		if((*it)->getID() == anID) return *it;
	T* temp = collection.find(anID);

	if (temp != NULL){
		return temp;
	}
	return NULL;
}

template <typename T>
T* MyTunesCollection<T>::findByID(const string & aUserID) {
//	for (vector<T>::iterator itr = collection.begin() ; itr != collection.end(); ++itr)
//		if(((*itr)->getUserID()).compare(aUserID) == 0) return *itr;
	int i =0;
	while(collection[i] != collection.end()){
		if (collection[i]->getUserID() == aUserID);{
			return collection[i];
		}

	}
	return NULL;
}

//template <typename T>
//typename vector<T*>::iterator MyTunesCollection<T>::findPosition(T & aElement){
//	for (typename vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
//		if(*it == &aElement) return it;
//	return collection.end();
//}

template <typename T>
void MyTunesCollection<T>::add(T & aElement){
	//so every fucking thing has an int ID
	int temp = aElement.getID();
	collection.emplace(temp, aElement);
}

template <typename T>
void MyTunesCollection<T>::remove(T & aElement){
//	typename vector<T*>::iterator index = findPosition(aElement);
//	if(index != collection.end()) {
//		T * theT = *index;
//		collection.erase(index);
//		delete theT; //free the memory of theRecording
//	}

	int temp = aElement.getID();

	collection.erase(temp);
}
template <typename T>
void MyTunesCollection<T>::showOn(UI& view){
	view.printOutput("Collection:");
	for(int i=0; i<collection.size(); i++){
		view.printOutput((*collection[i]).toString());
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