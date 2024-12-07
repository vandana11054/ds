

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    bool color;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* createNode(struct node* item,int key){
     struct node* one = (struct node*)malloc(sizeof(struct node));
     one->data = key;
     one->left = NULL;
     one->right = NULL;
     one->parent = NULL;
     one->color;        //1 for red and 0 for black
     item = one;
     return item;
}

struct node* rightRotate(struct node* item){
             struct node* x = item->left;
             item->left = x->right;
             if(item->left){
             x->right->parent = item;
             }
             if(item->parent->right == item){
                item->parent->right = x;
             }else if(item->parent->left == item){
                item->parent->left = x;
             }
             x->parent = item->parent;
             x->right = item;
             item->parent = x;
             return item;
}

struct node* leftRotate(struct node* item){
             struct node* x = item->right;
             item->right = x->left;
             if(item->right){
             x->left->parent = item;
             }
             if(item->parent->left == item){
                item->parent->left = x;
             }else if(item->parent->right == item){
                item->parent->right = x;
             }
             x->parent = item->parent;
             x->left = item;
             item->parent = x;
             return item;
}

struct node* search(struct node* item,int key){
          static int exists =1;
          if(item == NULL){
             if(exists == 0)  printf("given node do not exist in the tree");
             return item;
          }
          if(key < item->data){
              search(item->left,key);
          }
          if(key > item->data){
              search(item->right,key);
          }
          else if(key == item->data){
              return item;
          }
}

struct node* correct(struct node* temp){
     if(temp == NULL) return temp;
     if(temp->parent == NULL) temp->color =0;
     while(temp->parent->color){
         if(temp->parent->parent->left == temp->parent){
              if(temp->parent->parent->right->color == 1){
                   temp->parent->parent->right->color =0;
                   temp->parent->color =0;
                   temp->parent->parent->color =1;
                   temp = temp->parent->parent;     
              }
              else if(temp->parent->right == temp){
               temp=temp->parent;
               leftRotate(temp);
               temp->parent->color=0;
               temp->parent->parent->color=1;
               rightRotate(temp->parent->parent);
              }
         }
         if(temp->parent->parent->right == temp->parent){
              if(temp->parent->parent->left->color == 1){
                   temp->parent->parent->left->color =0;
                   temp->parent->color =0;
                   temp->parent->parent->color =1;
                   temp = temp->parent->parent;     
              }
              else if(temp->parent->left == temp){
               temp=temp->parent;
               rightRotate(temp);
               temp->parent->color=0;
               temp->parent->parent->color=1;
               leftRotate(temp->parent->parent);
              }
         }
     }  
     return temp; 
}

struct node* insert(struct node* item, struct node* temp){
     if(item == NULL){
       item = createNode(item,temp->data);
       item -> color=0;
       return item;
     }
     struct node* R = item;
     struct node* y= NULL;
      while(item != NULL){
        y = item;
      if(temp->data < item->data){
        item = item->left;
        if(item == NULL) break;
      }
      if(temp->data > item->data){
        item = item->right;
        if(item == NULL) break;
      }
     }
     if(temp->data < y->data){
         if(y->left != NULL) y=y->left;
      y->left = createNode(y->left,temp->data);
     }
     else if (temp->data > y->data){
          if(y->right != NULL) y=y->right;
      y->right = createNode(y->right,temp->data);
     }
     temp->parent = y;
     temp->color = 1;
     temp->left=NULL;
     temp->right=NULL;
     temp = correct(temp);
     item = R;
     return item;
}


int main(){
     struct node* root = NULL;
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp->left = NULL;
     temp->right = NULL;
     temp->parent = NULL;
     temp->data = 9;
     root = insert(root,temp);
     temp->data = 8;
     root = insert(root,temp);
     
     temp->data = 5;                                 
     root = insert(root,temp);
     
     temp->data = 4;
     root = insert(root,temp);
     
     temp->data = 99;
     root = insert(root,temp);
    
     temp->data = 78;
     root = insert(root,temp);
     
     temp->data = 31;
     root = insert(root,temp);
      
      temp->data = 34;
     root = insert(root,temp);
       
      temp->data = 89;
     root = insert(root,temp);
       
     temp->data = 90;
     root = insert(root,temp);
       
      temp->data = 21;
     root = insert(root,temp);
       
      temp->data = 23;
     root = insert(root,temp);
       
      temp->data = 45;
     root = insert(root,temp);
       
      temp->data = 77;
     root = insert(root,temp);
       
      temp->data = 88;
     root = insert(root,temp);
       
      temp->data = 112;
     root = insert(root,temp);
      
      temp->data = 32;
     root = insert(root,temp);
     
}

