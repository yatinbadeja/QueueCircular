#include <iostream>
using namespace std;
class CircularQueue{
    public:
    int front;
    int rear;
    int *array;
    int size;

    CircularQueue(int size){
        this->size=size;
        array = new int [size];
        front=-1;
        rear=-1;
    }
    void enqueue(int data){
        if((rear+1)%(size)==front){
            cout<<"Circular Queue is Full"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
          front++;
          rear++;
          array[rear]=data;
          return;
        }
        rear=(rear+1)%size;
        array[rear]=data;
    }
    void display(){
        cout<<"The Circular Queue is : ";
        for(int i=front;i!=(rear+1);i++){
            i=(i)%size;
            cout<<array[i]<<" ";
        }cout<<endl;
    }
    void getFront(){
        cout<<"The Front Element in Queue is : "<<array[front]<<endl;
    }
    void dequeue(){
        if(front==-1 && rear==-1){
            cout<<"Queue is Empty."<<endl;
            return;
        }
        else if(rear==front){
            cout<<"The Deleted Element is : "<<array[front]<<endl;
            rear=-1;
            front=-1;
            return;
        }
        cout<<"The Deleted Element is : "<<array[front]<<endl;
        front=(front+1)%size;
    }
    void isEmpty(){
        if(front==-1 && rear==-1){
            cout<<"The Queue is empty."<<endl;
            return;
        }cout<<"The Queue is not empty"<<endl;
    }
};
int main(){
        CircularQueue C_queue1(5);
        cout<<"1. Press 1 for insertion in a queue."<<endl
            <<"2. Press 2 for deletion in a queue."<<endl
            <<"3. Press 3 for front element in a queue."<<endl
            <<"4. Press 4 for checking whether queue is empty."<<endl
            <<"5. Press 5 for display Circular queue"<<endl
            <<"6. Press 6 for Exit."<<endl;
        int input,data;
        do{
            cout<<"Select a Option.";
            cin>>input;

            switch(input){
            case 1 : cout<<"Enter the Values.";
                     cin>>data; 
                     C_queue1.enqueue(data);
                     break;
            case 2 : C_queue1.dequeue();
                     break;
            case 3 : C_queue1.getFront();
                     break;
            case 4 : C_queue1.isEmpty();
                     break;
            case 5 : C_queue1.display();                                   
            }
        }while(input!=6);
}