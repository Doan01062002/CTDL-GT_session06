#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack{
	int arr[MAX];
	int top;
}Stack;

void initStack(Stack*s){
	s->top = -1;
}

void push(Stack*s, int value){
	s->arr[++s->top] = value;
}

void listStack(Stack*s,int n){
	for(int i= 0; i<n; i++){
		int temp;
		printf("Nhap gia tri: ");
		scanf("%d", &temp);
		
		s->arr[++s->top] = temp;
	}
	
	printf("\n");
}

void reveseListStack(Stack*s){
	int start = 0, end = s->top;
    while (start < end) {
        int temp = s->arr[start];
        s->arr[start] = s->arr[end];
        s->arr[end] = temp;
        start++;
        end--;
    }
}

//Ham hien thi tat ca cac phan tu trong ngan xep
void display(Stack*s){
	
	printf("Cac phan tu trong ngan xep: \n");
	for(int i=s->top; i>=0; i--){
		printf("%d->", s->arr[i]);
	}
	
	printf("\n");
}

int main(){
	int n;
	Stack s;
	initStack(&s);
	
	do{
		printf("Vui long nhap so luong phan tu voi 0<n<100: ");
		scanf("%d", &n);
	}while(n<0 || n>100);
	
	listStack(&s, n);
	
	display(&s);
	
	reveseListStack(&s);
	printf("Ham sau khi dao nguoc: \n");
	display(&s);
	
	return 0;
}
