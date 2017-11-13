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

#ifndef _RECORDINGS_H
#define _RECORDINGS_H

#include <ostream>
#include <vector>
#include <string>

#include "UI.h"
#include "recording.h"
using namespace std;
template <typename T>
class MyTunesCollection {
	public:
    MyTunesCollection();
	~MyTunesCollection(void);
    T* findByID(int anID);
	vector<T*> getCollection();
	void add(T & aElement);
	void remove(T & aElement);
	void showOn(UI & aView);
	void showOn(UI & aView, int memberID);
	private:
	vector<T*> collection;
	vector<T*>::iterator findPosition(T& aElement);
};
MyTunesCollection::MyTunesCollection(){}
MyTunesCollection::~MyTunesCollection(void){
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Recordings in this container
}
template <typename T> vector<T*> MyTunesCollection::getCollection(){return collection;}

template <typename T> T* findByID(int anID){
    for (vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
        if((*it)->getID() == anID) return *it;
    return NULL;
}
template <typename T> vector<T*>::iterator MyTunesCollection::findPosition(T & aElement){
	for (vector<T*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aElement) return it;
	return collection.end();
}
template <typename T> void MyTunesCollection::add(T & aElement){
	collection.push_back(&aRecording);
}
template <typename T> void MyTunesCollection::remove(T & aElement){
	typename vector<T*>::iterator index = findPosition(aElement);
	if(index != collection.end()) {
		T * theT = *index;
		collection.erase(index);
		delete theT; //free the memory of theRecording
	}
}
template <typename T> void MyTunesCollection::showOn(UI & view)  {
	view.printOutput("Collection:");
	for(int i=0; i<collection.size(); i++){
		view.printOutput((*collection[i]).toString());
	}
}
template <typename T> void MyTunesCollection::showOn(UI & view, int memberID)  {
	T * type = findByID(memberID);
	if( type != NULL)
		view.printOutput(type->toString());
}

#endif