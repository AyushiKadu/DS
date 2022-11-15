#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;

struct node *insert(struct node *tree, int x)
{
    struct node *p,*temp,*root;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;

    if(tree==NULL)
    {
        tree=p;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        root=NULL;
        temp=tree;
        while(temp!=NULL)
        {
            root=temp;
            if(x<temp->data)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(x<root->data)
        {
            root->left=p;
        }
        else
        {
            root->right=p;
        }
    }
    return tree;
}

void create(struct node *tree)
{
    tree=NULL;
}

void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d",tree->data);
        inorder(tree->right);
    }
}

void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d",tree->data);
    }
}

void main()
{
    printf("\nWELCOME TO IMPLEMENTATION OF BINARY TREE\n");
    int choice,x;
    struct node *ptr;
    create(tree);
    do
    {
        printf("\nOptions Available\n");
        printf("\n 1.Insert a node\n");
        printf("\n 2.Display Inorder traversal\n");
        printf("\n 3.Display preorder traversal\n");
        printf("\n 4.Display postorder traversal\n");
        printf("\n 5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter data to be inserted:");
                scanf("%d",&x);
                tree=insert(tree,x);
                break;
            case 2:
                printf("Elements in the inorder traversal are:");
                inorder(tree);
                printf("\n");
                break;
            case 3:
                printf("Elements in preorder traversal are:");
                preorder(tree);
                printf("\n");
                break;
            case 4:
                printf("Elements in postorder traversal are:");
                postorder(tree);
                printf("\n");
                break;
            case 5:
                printf("Exit: Program Finished!!");
                break;
            default:
                printf("Enter a valid option (1,2,3,4,5)");
                break;
        }
    }while(choice!=5);
}