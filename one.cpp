#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct QNode //������ʽ�洢
{
	string data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;  //����ͷָ��
	QueuePtr rear;   //����βָ��
}LinkQueue;

void menu();        //��ʾ�˵�
void initQueue(LinkQueue &Q);         //��ʼ������
void EnQueue(LinkQueue &Q,string e);  //�����
void DeQueue(LinkQueue &Q,string &e); //������
int QueueLength(LinkQueue &Q);        //���������Ԫ�ظ���
LinkQueue Ready;    //��������
LinkQueue Blocked;  //��������
LinkQueue Running;  //ִ�ж���


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
	//cout<<"���";
}
void DeQueue(LinkQueue &Q,string &e)
{
	QNode *p;
	if(Q.front==Q.rear)
	{
		return;
	}
	p=Q.front->next;         //ע�����о��ǴӶ�ͷ��ʼɾ��
	e=p->data;
	Q.front->next=p->next;   //�޸�ͷָ��
	if(Q.rear==p)
	{
		Q.rear=Q.front;
	}
	delete p;
	cout<<e;
}

int QueueLength(LinkQueue &Q)//���������Ԫ�ظ���
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
	cout<<"\tѡ��Ҫִ�е����"<<endl;
	cout<<"\t0-------����"<<endl;
	cout<<"\t1-------��������"<<endl;
	cout<<"\t2-------��������"<<endl;
	cout<<"\t3-------���Ƚ���"<<endl;
	cout<<"\t4-------��������"<<endl;
	cout<<"\t5-------���ѽ���"<<endl;
	cout<<"\t6-------ʱ��Ƭ"<<endl;
}
