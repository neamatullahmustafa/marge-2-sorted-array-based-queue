#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int checksorted(queue<int> myqueue)
{
	queue<int> temp;
	int x = 1,
		x1 = myqueue.front();
	myqueue.pop();
	int x2 = myqueue.front();
	myqueue.pop();
	while (!myqueue.empty())
	{
		if (x1 >= x2)
			x = 0;
		temp.push(x1);
		x1 = x2;
		x2 = myqueue.front();
		myqueue.pop();
	}
	if (x1 >= x2)
		x = 0;
	myqueue.push(x1);
	myqueue.push(x2);
	while (!temp.empty())
	{
		myqueue.push(temp.front());
		myqueue.pop();
	}
	return x;
}
void merge_2_sorted(queue<int> myqueue1, queue<int> myqueue2, queue<int>
	myqueue3)
{
	int x1 = myqueue1.front(), x2 = myqueue2.front();
	myqueue1.pop();
	myqueue2.pop();
	while (!myqueue1.empty() && !myqueue2.empty())
	{
		if (x1 < x2)
		{
			myqueue3.push(x1);
			x1 = myqueue1.front();
			myqueue1.pop();
		}
		else
		{
			myqueue3.push(x2);
			x2 = myqueue2.front();
			myqueue2.pop();
		}
	}
	while (!myqueue1.empty())
	{
		if (x1 < x2)
		{
			myqueue3.push(x1);
			x1 = myqueue1.front();
			myqueue1.pop();
		}
		else
		{
			myqueue3.push(x2);
			x2 = 10000000;
		}
	}
	while (!myqueue2.empty())
	{
		if (x2 < x1)
		{
			myqueue3.push(x2);
			x2 = myqueue2.front();
			myqueue2.pop();
		}
		else
		{
			myqueue3.push(x1);
			x2 = 10000000;
		}
	}
}
void insertnum(queue<int>myqueue, int num)
{
	queue<int> temp;
	int x = myqueue.front();
	myqueue.pop();
	while (!myqueue.empty())
	{
		if (x < num)
		{
			temp.push(x);
			x = myqueue.front();
			myqueue.pop();
		}
		else
		{
			temp.push(num);
			temp.push(x);
			break;
		}
	}
	while (!myqueue.empty())
	{
		temp.push(x);
		x = myqueue.front();
		myqueue.pop();
	}
	while (!temp.empty())
	{
		myqueue.push(temp.front());
		myqueue.pop();
	}
}
void sowap(queue<int>myqueue)
{
	queue<int> temp;
	int frist = myqueue.front(), last = 0;
	myqueue.pop();
	while (!myqueue.empty())
	{
		temp.push(last);
		last = myqueue.front();
		myqueue.pop();
	}
	myqueue.push(last);
	while (!temp.empty())
	{
		myqueue.push(temp.front());
		myqueue.pop();
	}
	myqueue.push(frist);
}
int main()
{}
