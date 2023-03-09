//Food Ordering system//
#include<stdio.h>
#include<process.h>
#include<string.h>
# define N 50
int rear=-1,front=-1;
int i,j;
char queue_array[N][N];
char str[N];
void dequeue(){
	if(front==-1){
		printf("\nFood Queue Empty !");
	}
	else if(front==rear){
		printf("\nFood Queue Empty !");
	}
	else{
		printf("\n\n%s is delivered\n",queue_array[front]);
		front=front+1;
		printf("\nREMAINING ORDERS - ");
		for(j=front;j<=rear;j++){
			printf("\n%s",queue_array[j]);
		}
	}
}
void display(){
	if(front==-1){
		printf("\nFood Queue Empty !");
	}
	else{
		printf("\nYour Order - ");
		for(j=front;j<=rear;j++){
			printf("\n\nFOOD - %s",queue_array[j]);
		}
	}
}
void enqueue(char str[N]){
	if(rear==N-1){
		printf("\nFood Queue Overflow !");
	}
	else{
		if(front==-1){
			front=0;
		}
		rear=rear+1;
		strcpy(queue_array[rear],str);
		printf("\nFood Ordered.");
	}
}
void main(){
	int op,c,ch,qty,price;
	char od;
	printf("\tFOOD ORDERING");
	printf("\n\t=============");
	do{
		printf("\n\n1. ORDER\n2. VIEW ORDER\n3. ORDER DELIVERED\n4. EXIT");
		printf("\nChoose your option : ");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nMENU - \n1. BBQ\n2. SHAKES\n3. BURGER\nSelect your choice : ");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						printf("\nSelected Food Item : BBQ");
						enqueue("BBQ");
						break;
					case 2:
						printf("\nSelected Food Item : SHAKES");
						enqueue("SHAKES");
						break;
					case 3:
						printf("\nSelected Food Item : BURGER");
						enqueue("BURGER");
						break;
					default:
						printf("\nWrong Choice !");		
						break;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				printf("\nWas the order delivered ? (Y/N) : ");
				getchar();
				scanf("%c",&od);
				if(od=='Y'||od=='y'){
					dequeue();					
				}
				else{
					printf("\n");
					main();
				}
				break;
			case 4:
				exit(0);
			default:
				printf("\nWrong Choice !");				
		}
	}while(1);
}
