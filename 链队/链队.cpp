// 链队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

typedef struct QNode
{
	int data;
	QNode *qNext;
}*QPtr;

typedef struct Queue
{
	QPtr front;
	QPtr rear;
}LinkQueue;

void InitQueue(LinkQueue &q)
{
	q.front = q.rear = new QNode;
	q.front->qNext = NULL;
}

void EnQueue(LinkQueue &q, int *e,int len)
{
	QPtr p;
	for (int i = 0; i < len; i++)
	{
		p = new QNode;
		p->data = e[i];
		p->qNext = NULL;
		q.rear->qNext = p;
		q.rear = p;
	}
	cout << "入队成功！" << endl;
}

int GetHead(LinkQueue q)
{
	if (q.front != q.rear)
		return q.front->qNext->data;
}
void Display(LinkQueue q)
{
	if (q.front==q.rear)cout << "队空！" << endl;
	else
	{
		QPtr p;
		p = q.front->qNext;
		int i = 0;
		while (true)
		{
			if (p->qNext == NULL)
			{
				cout << p->data << endl;
				i++;
				break;
			}
			cout << p->data << " ";
			i++;
			p = p->qNext;
		}
		cout << "链队中共有元素" << i << "个" << endl;
	}
}

void DeQueue(LinkQueue &q, int &out)
{
	if (q.front == q.rear) cout << "队空！" << endl;
	else
	{
		QPtr p;
		p = q.front->qNext;
		out = p->data;
		q.front->qNext = p->qNext;
		if (q.front == p)q.rear = q.front;
	}
}
int main()
{
	LinkQueue q;
	InitQueue(q);
	int *num, len;
	cout << "请输入想插入链表的元素的个数：";
	cin >> len;
	num = new int[len];
	cout << "请逐一输入：" << endl;
	for (int i = 0; i < len; i++)
		cin >> num[i];
	EnQueue(q, num, len);
	Display(q);
	cout << "队头元素：" << GetHead(q) << endl;
	int temp;
	DeQueue(q, temp);
	cout << "出队元素：" << temp << endl;
	Display(q);
}

