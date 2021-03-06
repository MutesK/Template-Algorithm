#pragma once

template <class T>
class CQueue
{
private:
	enum {
		DATAMAX = 100
	};

	int front;
	int rear;

	T Data[DATAMAX];
	int NextPosIdx(int* pos)
	{
		if (*pos == DATAMAX - 1)
			return 0;
		else
			*pos = (*pos + 1) % DATAMAX;
		return true;
	}
	bool Peek(T *out)
	{
		if (front == rear)
			return true;

		*out = NextPosIdx(front);
	}
public:
	CQueue();

	bool Dequeue(T *pData);
	void Enqueue(T data);
	int getSize();
	int freeSize();
	bool Peek(T *out, int pos);
};

template <class T>
CQueue<T>::CQueue()
	:front(0), rear(0)
{
}


template <class T>
void CQueue<T>::Enqueue(T data)
{
	if ((rear + 1) % DATAMAX != front)
	{
		Data[rear] = data;
		rear = (rear + 1) % DATAMAX;
	}
}

template <class T>
bool CQueue<T>::Dequeue(T *pData)
{
	if (front != rear)
	{
		*pData = Data[front];
		front = (front + 1) % DATAMAX;

		return true;
	}
	return false;
}

template <class T>
int CQueue<T>::getSize()
{
	if (front < rear)
		return rear - front + 1;
	else if ((rear + 1) % DATAMAX == front)
		return DATAMAX - 1;
	else
		return (DATAMAX - ((DATAMAX - front) + (rear + 1)));
}


template <class T>
int CQueue<T>::freeSize()
{
	return (DATAMAX - 1) - getSize();
}

template <class T>
bool CQueue<T>::Peek(T *out, int pos)
{
	if (front != rear)
	{
		int tFront = front;

		tFront = (tFront + pos) % DATAMAX;

		if (tFront != rear)
		{
			*out = Data[tFront];
			return true;
		}
	}
	return false;
}