#include<stdio.h>
#include<iostream>
#include<string.h>
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
void QueueTraverse(LinkQueue &Q);     //遍历队列中元素并显示
void GetHead(LinkQueue &Q);           //取队头元素
bool QueueEmpty(LinkQueue &Q);        //判断队列是否为空

LinkQueue Ready;    //就绪队列
LinkQueue Blocked;  //阻塞队列
LinkQueue Running;  //执行队列

void create();//创建进程
void stop();//撤销（终止）进程
void block();//阻塞进程
void order();//自动调度
void wake(); //唤醒进程
void time();//时间片用完
int main()
{
	menu();
	initQueue(Ready);
	initQueue(Blocked);
	initQueue(Running);
	//EnQueue(Ready,"s");
    	//len=QueueLength(Ready);
	//cout<<len;
	//DeQueue(Ready,s);
	int num;
    	bool flg=true;
	menu();
    	cout<<"which do you want to choose?\n";
    	do
    	{

        	cout<<"I choose ";
        	cin>>num;
        	switch(num)
        	{
	            	case 1:create();break;
	            	case 2:stop();break;
	            	//case 3:order();break;
	            	case 3:block();break;
	            	case 4:wake();break;
	            	case 5:time();break;
	            	case 0:flg=false;break;
	            	default:break;
        	}
	        if(QueueEmpty(Running))
	        {
	            order();
	        }
	        cout<<"\tReady:";QueueTraverse(Ready);cout<<"\n";
	        cout<<"\tRunning:";QueueTraverse(Running);cout<<"\n";
	        cout<<"\tBlocked:";QueueTraverse(Blocked);cout<<"\n";
	        cout<<"------------------------------------\n";
	    }while(flg);


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
void QueueTraverse(LinkQueue &Q)//遍历队列中元素并显示
{
    QueuePtr p;
    p=Q.front->next;
    if(p==NULL)
    {
        return;
    }
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    printf("\n");
}
void GetHead(LinkQueue &Q)//取队头元素
{
    if(Q.front!=Q.rear)
    {
        head=Q.front->next->data;
    }
    return;
}
bool QueueEmpty(LinkQueue &Q)//判断队列是否为空
{
    if(Q.front==Q.rear && Q.front!=NULL)//队列为空，返回true
    {
        return true;
    }
    else
    {
        return false;
    }
}
void menu()
{
	cout<<"\t选择要执行的命令："<<endl;
	cout<<"\t0-------退出"<<endl;
	cout<<"\t1-------创建进程"<<endl;
	cout<<"\t2-------撤销进程"<<endl;
	cout<<"\t3-------阻塞进程"<<endl;
	cout<<"\t4-------唤醒进程"<<endl;
	cout<<"\t5-------时间片"<<endl;
}
void create()//创建进程
{
    string str;
    cout<<"the name of creation:";
    cin>>str;
    if(QueueEmpty(Running))//Running为空
    {
        EnQueue(Running,str);
    }
    else
    {
        EnQueue(Ready,str);
    }
    return;
}
void stop()//撤销（终止）进程
{
    if(QueueEmpty(Running))//Running为空
    {
        cout<<"不能执行，因为没有正在执行的程序！\n";
    }
    else
    {
        DeQueue(Running);
    }
}
void block()//阻塞进程
{
    if(QueueEmpty(Running))//Running为空
    {
        cout<<"不能执行，因为没有正在执行的程序！\n";
    }
    else
    {
        DeQueue(Running);
        EnQueue(Blocked,head);
    }
}
void wake()//唤醒进程
{
    if(QueueEmpty(Blocked))//Blocked为空
    {
        cout<<"不能执行，因为没有在阻塞态的程序！\n";
    }
    else
    {
        DeQueue(Blocked);
        EnQueue(Ready,head);
    }
}
void order()//自动调度
{
    if(QueueEmpty(Ready))//Ready为空
    {
        //cout<<"不能执行，因为没有在就绪态的程序！\n";
        return;
    }
    else
    {
        DeQueue(Ready);
        EnQueue(Running,head);
    }
}
void time()//时间片用完
{
    if(QueueEmpty(Running))//Running为空
    {
        cout<<"不能执行，因为没有正在执行的程序！\n";
    }
    else
    {
        DeQueue(Running);
        EnQueue(Ready,head);
    }
}
