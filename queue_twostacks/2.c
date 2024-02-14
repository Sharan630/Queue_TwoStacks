#include<stdio.h>
#include<stdbool.h>
int stack[100001];
int top=-1;
bool isFull(){
    if(top==100001){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}
void push(int n){
    if(isFull()){
        return;
    }
    top++;
    stack[top]=n;
}

void pop(){
    if(isEmpty()){
        return;
    }
    top--;    
}

void enqueue(int n){
    push(n);
}
void dequeue(){
    int stack2[100001];
    int top2=-1;
    while(top!=-1){
        top2++;
        stack2[top2]=stack[top];
        top--;
    }
    top2--;
    while(top2!=-1){
        top++;
        stack[top]=stack2[top2];
        top2--;
    }
}
int front(){
    return stack[0];
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int q;
        scanf("%d",&q);
        int n;
        switch (q) {
            case 1:
               scanf("%d",&n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("%d\n",front());
                break;
        }
    }
    return 0;
}