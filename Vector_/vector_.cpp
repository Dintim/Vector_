#include "vector_.h"



vector_::vector_()
{
	this->arr = nullptr;
	this->size = 0;
}


vector_::~vector_()
{
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = nullptr;
	this->size = 0;
}

vector_::vector_(const vector_ & vec)
{
	this->size = vec.size;
	if (this->size == 0) {
		this->arr = nullptr;
		return;
	}
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = vec.arr[i];
}

vector_::vector_(int size, int element)
{
	if (size == 0)
		return;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = element;
	this->size = size;
}

bool vector_::empty() const
{
	return this->size==0;
}

int vector_::getSize() const
{
	return this->size;
}

void vector_::clear()
{
	this->~vector_();
}

void vector_::push_back(int number)
{
	int* tmp = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
		tmp[i] = this->arr[i];
	tmp[this->size] = number;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;
}

void vector_::pop_back()
{
	if (this->size <= 0) return;
	if (this->size == 1) {
		this->~vector_();
		return;
	}
	int* tmp = new int[this->size - 1];
	for (int i = 0; i < this->size - 1; i++)
		tmp[i] = this->arr[i];
	delete[] this->arr;
	this->arr = tmp;
	this->size--;
}

void vector_::erase(int index)
{
	if (this->size <= 0 || index<0 || index>this->size)
		return;
	int* tmp = new int[this->size - 1];
	int k = 0;
	for (int i = 0; i < index; i++)
		tmp[k++] = this->arr[i];
	for (int i = index + 1; i < this->size; i++)
		tmp[k++] = this->arr[i];
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}

void vector_::insert(int index, int number)
{
	if (this->size <= 0 || index<0 || index>this->size)
		return;
	int* tmp = new int[this->size + 1];
	for (int i = 0; i < index; i++)
		tmp[i] = this->arr[i];
	tmp[index] = number;
	for (int i = index, j = index + 1; i < this->size; i++, j++)
		tmp[j] = this->arr[i];
	delete[] this->arr;
	this->arr = tmp;
	this->size++;
}

int & vector_::operator[](int index) const
{
	return this->arr[index];
}

ostream & operator<<(ostream & os, const vector_ & vec)
{
	for (int i = 0; i < vec.getSize(); i++)
		os << vec[i] << " ";
	return os;
}

istream & operator>>(istream & is, vector_ & vec)
{
	int tmp;
	for (int i = 0; i < vec.getSize(); i++) {
		is >> tmp;
		vec[i] = tmp;
	}
	return is;
}
