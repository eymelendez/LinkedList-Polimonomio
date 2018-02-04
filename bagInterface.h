// bagInterface.h

#pragma once

#include<iostream>
#include<vector>
using namespace::std;

#pragma once
template<class ItemType>
class bagInterface
{
public:
	virtual int getCurrentSize() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool add(const ItemType& newEntry) = 0;
	virtual bool remove(const ItemType& anEntry) = 0;
	virtual void clear() = 0;
	virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
	virtual bool contains(const ItemType& anEntry) const = 0;
	virtual vector<ItemType> toVector() const = 0;

};