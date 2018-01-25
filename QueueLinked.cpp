#include <iostream>
#include "QueueLinked.h"
#include "Queue.h"


template<typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
	front = NULL;
	back = NULL;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked &other)
{
	(*this) = other;
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	QueueNode* cursor;
	QueueNode* temp;
	QueueNode* nextItem;

	
	if((*this) == other)
		return this;

	while(cursor != NULL)
	{
		if(cursor->next == NULL)
		{
			temp->next = NULL;
			back = temp;
			break;
		}		
		cursor = other->front;
		temp = front;
		nextItem = new QueueNode(NULL, NULL);
		temp->next = nextItem;
		temp = temp->next;
		cursor = cursor->next;
		
	}

	return;

	
	
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
}

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if(isFull())
	{
		throw logic_error("enqueue() queue full");
	}
	

	QueueNode* temp = new QueueNode(newDataItem, NULL);
	
	if(isEmpty())
	{
		front = temp;
		back = temp;
		return;
	}

	back->next = temp;
	back = temp;
	
	
	return;
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("dequeue() queue empty");
	} 
	
	QueueNode* temp;
	DataType value = front->dataItem;
	temp = front;
	front = front->next;
		
	
	delete[] temp;

	return value;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	QueueNode* temp = front;
	QueueNode* deleteTemp;

	if(isEmpty() == true)
		return;
	
	while(temp != NULL)
	{
		deleteTemp = temp;
		temp = temp->next;
		delete[] deleteTemp;
	}

	front = NULL;
	back = NULL;
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if(front == NULL)
	{
		return true;
	}

	return false;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if(isFull())
	{
		throw logic_error("enqueue() queue empty");
	}

	QueueNode* temp = new QueueNode(newDataItem, front);
	int length = getLength();

	
	

	
	front = temp;
	if(getLength() == 1)
	{
		back = temp;
	}
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	QueueNode* temp;
	temp = front;
	DataType dataItemClone;


	if (isEmpty()) {
		throw logic_error("getRear() queue empty");
	} 


	if(getLength() == 1)
	{
		dataItemClone = temp->dataItem;
		clear();
		return dataItemClone;
	}

	while(temp->next != back)
	{
		temp = temp->next;
	}

	dataItemClone = back->dataItem;
	
	delete[] back;
	temp->next = NULL;
	back = temp;
	

	return dataItemClone;

	

}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	QueueNode* temp = front;
	int count = 0;

	while(temp != NULL)
	{
		count += 1;
		temp = temp->next;
	}

	return count;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
	QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}



