#include<stdio.h>
int stack[100],top=-1,i,j,n,x,choice;
void push();
void pop();
void peep();
void display();

void push()
{
    if(top>=n-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed: \n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The popped element is %d\n",stack[top]);
        top--;
    }
}

void peep()
{
    printf("Enter the position of the element you want to peep: \n");
    scanf("%d",&i);
    if(top-i+1<0)
    {
        printf("Stack Underflow for peep\n");
    }
    else
    {
        printf("The %d element from the top is %d\n",i,stack[top-i+1]);
    }
}

void display()
{
    if(top<0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The elements in stack are: \n");
        for(j=top;j>-1;j--)
        {
            printf("%d\n",stack[j]);
        }
    }
}

void main()
{
    printf("Enter size of stack: \n");
    scanf("%d",&n);
    do{
        printf("The choices available are: \n");
        printf("\t1.Push\t2.Pop\t3.Peep\t4.Display\t5.Exit\n");
        printf("Enter a valid choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: peep();
                break;
            case 4: display();
                break;
            case 5: printf("Exit!!");
                break;
            default: printf("Enter a valid choice\n");
                break;
        }
    }while(choice!=5);
}