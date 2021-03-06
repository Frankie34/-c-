#include <cstdio>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType * base;
    int front;
    int rear;
}SqQueue;

int InitQueue(SqQueue &Q) { //构造一个空队列Q
    Q.base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    if (!Q.base) return 0;//存储分配失败
    Q.front=Q.rear=0;
    return 1;
}

int QueueLength(SqQueue &Q) { //计算队列的长度
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

int EnQueue(SqQueue &Q, ElemType e) { //插入元素e入队列Q
    if ((Q.rear+1)%MAXSIZE == Q.front) return 0;//队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXSIZE; return 1;
}


int DeQueue(SqQueue &Q, ElemType &e)

{
// 从队列Q取数据放入e
    if (Q.rear == Q.front)
    return 0;//队列满
    e =Q.base[Q.front] ;
    Q.front = (Q.front+1)%MAXSIZE;
    return 1;
}



int main() {
    SqQueue S1;
    int i,res;
    ElemType e1,e2;
    printf("输入： 0：队列初始化 1：入队 2：出队");
    while(scanf("%d",&i)!=EOF) {
        if(i==0) {
            InitQueue(S1);
        }else if(i==1) {
            printf("入队：");
            scanf("%d",&e1);
            res = EnQueue(S1,e1);
            if(res == 1) {
                printf("DONE");
            }
        }else if(i==2) {
            printf("出队：");
            res = DeQueue(S1,e2);
            if(res){printf("%d\n",e2);}
            else printf("Error");
        }else printf("Error");;
    }
    return 0;
}


/*
#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType elem[MAXSIZE];
    int front,rear; //队头、队尾指针
}SqQueue;

void InitQueue(SqQueue *Sq) { //将循环队列Sq初始化
    Sq->front=Sq->rear=0;
} //InitQueue

int EnQueue(SqQueue *Sq,ElemType x) { // 在循环队列Sq的尾部插入一个新的元素x
    if( (Sq->rear+1) % MAXSIZE == Sq->front) return 0;
    Sq->elem[Sq->rear]=x;
    Sq->rear=(Sq->rear+1) % MAXSIZE; return 1;
} // EnQueue

int DelQueue(SqQueue *Sq,ElemType *y) { //删除循环队列Sq的队头元素，并存人*y中
    if(Sq->front==Sq->rear) return 0;
    *y=Sq->elem[Sq->front];
    Sq->front=(Sq->front+1) % MAXSIZE ;
    return 1;
} // DelQueue
*/