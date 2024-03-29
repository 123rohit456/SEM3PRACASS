#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree *insert(struct tree *,int);
struct tree *create(int);
struct tree *search(struct tree *,int);
void inorder(struct tree *);
struct tree *delete(struct tree *,int);
int inorderS(struct tree *);

struct tree *create(int d)
{
    struct tree *new;
    new=(struct tree *)malloc(sizeof(struct tree));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct tree *insert(struct tree *root,int d)
{
    if(root==NULL)
    {
        return create(d);
    }
    else if(d<root->data)
    {root->left=insert(root->left,d);}
    else
    {root->right=insert(root->right,d);}
    return root;
}

void inorder(struct tree *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(root!=NULL)
        inorder(root->left);
        printf("%d,",root->data);
        inorder(root->right);
    }
}

struct tree *search(struct tree *root,int d)
{
    if(root==NULL)
    {  return root;}
    else if(d==root->data)
    {printf("Data found is %d \n",d);}
    else if(d<root->data)
    {root->left=search(root->left,d);}
    else
    {root->right=search(root->right,d);}
}

struct tree *delete(struct tree *root,int d)
{
    if(root==NULL)
    {
        return root;
    }
    if(d<root->data)
    root->left=delete(root->left,d);
    else if(d>root->data)
    root->right=delete(root->right,d);
    else
    {
        if(root->right==NULL)
        {
            struct tree *temp;
            temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            struct tree *temp;
            temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            struct tree *temp;
            temp=root->right;
            root->data=inorderS(temp);
            root->right=delete(root->right,root->data);
        }
    }
    return root;
}

int inorderS(struct tree *temp)
{
    while(temp && temp->left!=NULL)
    temp=temp->left;
    return temp->data;
}


void main()
{
    int ch,d,y;
    struct tree *root=NULL;
    printf("---------CREATION OF BINARY TREE-------------\n");
    do
    {
      printf("Enter choice : \n1.Insert \n2.Search \n3.Inorder traversal\n4.Delete\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:
          printf("\nEnter data ");
          scanf("%d",&d);
          root=insert(root,d);
          break;

          case 2:
          printf("\nEnter data to be searched : ");
          scanf("%d",&d);
          search(root,d);
          break;

          case 3:
          printf("\nInorder tree traversal : ");
          inorder(root);
          break;
          
          case 4:
          printf("\nEnter the element to be deleted : ");
          scanf("%d",&d);
          delete(root,d);
          break;
      }
      printf("\nDo you wish to continue(0/1)\n");
      scanf("%d",&y);
    }while(y==1);
}
