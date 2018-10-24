#pragma once
#include <iostream>
using namespace std;

class vector_
{
	int* arr;
	int size;
public:
	vector_();
	~vector_();
	vector_(const vector_&vec);
	vector_(int size, int element = 0);
	bool empty()const;
	int getSize()const;
	void clear();
	void push_back(int number);
	void pop_back();
	void erase(int index);
	void insert(int index, int number);
	int&operator[](int index)const;	
};

ostream&operator<<(ostream&os, const vector_&vec);
istream&operator>>(istream&is, vector_&vec);

