#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>



class circularStack{
    int front=-1,rear=-1;
    int size=5;
    std::string array[4];
public:
    void push(std::string);
    std::string pop();
};

void circularStack::push(std::string data){
    if(rear==-1){
        front=rear=0;
    }else if(front==0 && rear==(size-1)){
        rear=0;
        front=1;
    }else if((rear+1)%size==front){
        front=(front+1)%size;
        rear=(rear+1)%size;
    }else{
        rear=(rear+1)%size;
    }
    array[rear]=data;
}

std::string circularStack::pop(){
    if(rear==-1){
        return "21212";
    }
    std::string item=array[rear];
    if(front==rear){
        front=rear=-1;
    }else if(front<rear){
        rear--;
    }else if(rear==0){
        rear=size-1;
    }else{
        rear--;
    }

    return item;
}

int main()
{
   circularStack mstack;
   mstack.push("1");
   mstack.push("2");
   mstack.push("3");
   mstack.push("4");
   mstack.push("5");
   mstack.push("6");
   mstack.push("7");
   mstack.push("8");
   mstack.push("9");
   mstack.push("10");
   std::cout<<mstack.pop()<<std::endl;
   std::cout<<mstack.pop()<<std::endl;
   std::cout<<mstack.pop()<<std::endl;
   std::cout<<mstack.pop()<<std::endl;
   std::cout<<mstack.pop()<<std::endl;
   std::cout<<mstack.pop()<<std::endl;
}