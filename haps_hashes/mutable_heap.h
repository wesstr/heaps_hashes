#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

template <class T>
class mutable_heap
{
private:
	vector<T> heap;
	unordered_map<T, int> hash;

public:
	mutable_heap();

	void push(T data);
	T pop();
	void update_heap(T old_data, T new_data);
	T get_data(int pos);
	T get_hash(T data);
};


template <class T>
mutable_heap<T>::mutable_heap()
{
	heap.push_back(NULL);
}


template <class T>
void mutable_heap<T>::push(T data)
{

	//CODE FORM SLIDES
	int position = heap.size();
	int size = heap.size() + 1;
	int parent;

	heap.push_back(NULL);
	parent = (double)position / 2;

	while ((parent > 0) && (heap[parent] < data))
	{
		hash[heap[parent]] = position;
		heap[position] = heap[parent];
		position = parent;
		parent = (double)position / 2;
	}


	heap[position] = data;
	hash[data] = position;

}

template <class T>
T mutable_heap<T>::pop()
{
	T to_return = heap[1];
	heap[1] = NULL;
	heap.erase(heap.begin(),heap.begin()+1);
	hash.erase(to_return);
	
	if (heap[1] < heap[2])
	{
		T temp = heap[1];
		T temp2 = heap[2];
		heap[1] = temp2;
		heap[2] = temp;
		hash[temp] = 2;
		hash[temp2] = 1;
		
	}

	int position = heap.size();
	int size = heap.size() + 1;
	int parent = 0;

	heap.push_back(NULL);
	parent = (double)position / 2;

	while ((parent > 0) && (heap[parent] < heap[1]))
	{
		hash[heap[parent]] = position;
		heap[position] = heap[parent];
		position = parent;
		parent = (double)position / 2;
	}
	return to_return;
}

template <class T>
void mutable_heap<T>::update_heap(T old_data, T new_data)
{
	return NULL;
}

template <class T>
T mutable_heap<T>::get_data(int pos)
{

	return heap[pos];
}

template <class T>
T mutable_heap<T>::get_hash(T data)
{
	return hash[data];
}