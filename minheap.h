//
//  minheap.h
//  ERT35P3
//
//  Created by Elaina Teramoto
//  Copyright © 2017 Elaina Teramoto. All rights reserved.
//

#ifndef minheap_h
#define minheap_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class MinHeap {
    
public:
    MinHeap();
    
    int getChild1(int);
    int getChild2(int);
    int getParentIndex(int);
    bool hasChild1(int);
    bool hasChild2(int);
    bool hasParent(int);
    int child1(int);
    int child2(int);
    int parent(int);
    
    void swap(int, int);
    void swapUp();
    void swapDown();
    
    void ensureExtraCapacity();
    void remove();
    void add(int);
    void print(int);

    int size;
    int *items;
    
private:
    int capacity;
    
}; //Heap class

template<typename T>
MinHeap<T>::MinHeap()
{
    //initalizing
    capacity = 1;
    size = 0;
    items = new int[capacity];
}
template<typename T>
int MinHeap<T>:: getChild1(int parentIndex)
{
    //returns the left child index
    return 2* parentIndex +1;
}

template<typename T>
int MinHeap<T>::getChild2(int parentIndex)
{
    //return the right child index
    return 2* parentIndex +2;
}

template<typename T>
int MinHeap<T>::getParentIndex(int childIndex)
{
    //returns the parentIndex
    return (childIndex -1)/2;
}

template<typename T>
bool MinHeap<T>:: hasChild1(int index)
{
    //returns if it has a left child
    return getChild1(index)<size;
}

template<typename T>
bool MinHeap<T>::hasChild2(int index)
{
    //returns if it has a right child
    return getChild2(index)<size;
}

template<typename T>
bool MinHeap<T>::hasParent(int index)
{
    //returns if it has a parent
    return getParentIndex(index)>=0;
}

template<typename T>
int MinHeap<T>::child1(int index)
{
    //returns the value of the left child
    return items[getChild1(index)];
}

template<typename T>
int MinHeap<T>::child2(int index)
{
    //returns the value of the right child
    return items[getChild2(index)];
}

template<typename T>
int MinHeap<T>:: parent(int index)
{
    //returns the value of the parent child
    return items[getParentIndex(index)];
}

template<typename T>
void MinHeap<T>::swap(int indexOne, int indexTwo)
{
    //swaps the indexes while keeping the values
    int temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

template<typename T>
void MinHeap<T>::ensureExtraCapacity()
{
    if (size  == capacity)
    {
        //need to increase capacity so copy over array
        //delete the array
        capacity *=2;
        int *tempitems = new int [capacity];
        //iterate through array to copy all the items;
        for (int i = 0; i< size; i++)
        {
            tempitems[i] = items[i];
        }
        delete [] items;
        items = tempitems;
    }
}

template<typename T>
void MinHeap<T>::remove()
{
    if (size == 0)
    {
        //if there is nothing in the array then
        //no need to do anything
    }
    else
    {
        items[0] = items[size-1];
        size--;
        swapDown();
        print(0);
    }
    
}

template<typename T>
void MinHeap<T>::add(int item)
{
    //ensure that there is enough capacity
    // then add the item to the end of the
    // list and swap with parents
    ensureExtraCapacity();
    items[size] = item;
    size++;
    swapUp();
    print(0);
}

template<typename T>
void MinHeap<T>::swapUp()
{
    //keep swapping values until the children's value is
    //greater than parents values

    int index = size -1;
    while ((hasParent(index)) && parent(index)>items[index] )
    {
        swap(getParentIndex(index),index);
        index = getParentIndex(index);
    }
}

template<typename T>
void MinHeap<T>::swapDown()
{
    //keep swapping values until parent values
    // are less than children
    int index = 0;
    while (hasChild1(index))
    {
        int smallerChildIndex = getChild1(index);
        if (hasChild2(index) && child2(index)< child1(index) )
        {
            smallerChildIndex = getChild2(index);
        }
        if (items[index] < items[smallerChildIndex]){
            break;
        }
        else{
            swap(index,smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}

template<typename T>
void MinHeap<T>::print(const int index)
{
    if (size <1)
    {
        //if there is nothing in the array
        cout << "[]";
        return;
    }
    if (index > size-1)
    {
        return;
    }
    cout << "[" << items[index];
    print(getChild1(index));// print left
    print(getChild2(index)); //print right
    cout << "]";
}
#endif /* minheap_h */
