#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct QNode //队列链式存储
{
	string data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;  //队列头指针
	QueuePtr rear;   //队列尾指针
}LinkQueue;

void menu();        //显示菜单
void initQueue(LinkQueue &Q);         //初始化队列
void EnQueue(LinkQueue &Q,string e);  //入队列
void DeQueue(LinkQueue &Q,string &e); //出队列
int QueueLength(LinkQueue &Q);        //计算队列中元素个数
LinkQueue Ready;    //就绪队列
LinkQueue Blocked;  //阻塞队列
LinkQueue Running;  //执行队列


int main()
{
	//menu();
	string s;
	int len;
	initQueue(Ready);
	EnQueue(Ready,"s");
	EnQueue(Ready,"i");
	EnQueue(Ready,"x");
	EnQueue(Ready,"t");
    EnQueue(Ready,"h");

    len=QueueLength(Ready);
    cout<<len;


	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	DeQueue(Ready,s);
	return 0;
}

void initQueue(LinkQueue &Q)
{
	Q.front=Q.rear=new QNode;
	Q.front->next=NULL;
	Q.front->next=NULL;
	//return 0;
	//cout<<"ok";
}

void EnQueue(LinkQueue &Q,string e)
{
	QNode *p;
	p=new QNode;
	p->data=e;
	p->next=NULL;Q.rear->next=p;
	Q.rear=p;
	//cout<<"入队";
}
void DeQueue(LinkQueue &Q,string &e)
{
	QNode *p;
	if(Q.front==Q.rear)
	{
		return;
	}
	p=Q.front->next;         //注：队列就是从队头开始删除
	e=p->data;
	Q.front->next=p->next;   //修改头指针
	if(Q.rear==p)
	{
		Q.rear=Q.front;
	}
	delete p;
	cout<<e;
}

int QueueLength(LinkQueue &Q)//计算队列中元素个数
{
    QueuePtr p;
    int length=0;
    p=Q.front->next;
    while(p!=NULL)
    {
        length++;
        p=p->next;
    }
    return length;
}
void menu()
{
	cout<<"\t选择要执行的命令："<<endl;
	cout<<"\t0-------帮助"<<endl;
	cout<<"\t1-------创建进程"<<endl;
	cout<<"\t2-------撤销进程"<<endl;
	cout<<"\t3-------调度进程"<<endl;
	cout<<"\t4-------阻塞进程"<<endl;
	cout<<"\t5-------唤醒进程"<<endl;
	cout<<"\t6-------时间片"<<endl;
}
