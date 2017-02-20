#pragma once

template<class T>
class CStack
{
private:
	enum {
		DATAMAX = 100,
	};
	T Data[100];
	int top;
public:


	CStack()
	{
		top = -1;
	}
	~CStack() 
	{
	}

	bool push(T Data);
	bool pop(T* pData);
	int count()
	{
		return top;
	}
	void clear()
	{
		top = -1;
	}
	int getTop()
	{
		return top;
	}
};

template<class T>
bool CStack<T>::push(T aData)
{
	if (top >= DATAMAX - 1)
		return false;


	++top;
	Data[top] = aData;
}
template<class T>
bool CStack<T>::pop(T *pData) // 데이터를 리턴하기보다 성공여부를 리턴하는것이 좋다.
{
	if (top <= -1)
		return false;

	*pData = Data[top];
	top--;

	return true;
}