#include <bits/stdc++.h>

#define NIL NULL
#define INF 1000000001

using namespace std;

struct node {
    int key,priority;
    struct node *right;
    struct node *left;
};

typedef node * Node;


Node delete_(Node t,int key);
Node _delete(Node t,int key);

Node rightRotate(Node t){
    Node s = t->left;
    t->left  = s->right;
    s->right = t;
    return s;
}

Node leftRotate(Node t){
    Node s = t->right;
    t->right = s->left;
    s->left  = t;
    return s;
}

Node insert(Node t,int key,int priority){
    if(t == NIL){
        t = (Node)malloc(sizeof(struct node));
        t->key = key;
        t->priority = priority;
        t->left = NIL;t->right = NIL;
    }else if(t->key == key) return NIL; 

    if(key < t->key){
        t->left = insert(t->left,key,priority);
        if(t->priority < t->left->priority) t = rightRotate(t);
    }else if(key > t->key){
        t->right = insert(t->right,key,priority);
        if(t->priority < t->right->priority)t = leftRotate(t);
    }
    return t;
}

Node delete_(Node t,int key){
    if(t == NIL) return NIL;
    if(key < t->key) t->left = delete_(t->left,key);
    else if(key > t->key) t->right = delete_(t->right,key);
    else return _delete(t,key);
    return t;
}

Node _delete(Node t,int key){
    if(t->left ==NIL && t->right == NIL) return NIL;
    else if(t->left == NIL) t  = leftRotate(t);
    else if(t->right== NIL) t  = rightRotate(t);
    else{
        if(t->left->priority < t->right->priority) t = leftRotate(t);
        else t = rightRotate(t);
    }
    return delete_(t,key);
}

Node findElement(Node current_node,int v){
    if(current_node == NIL) return NIL;
    else if(current_node->key == v) return current_node;
    else if(current_node->key > v) return findElement(current_node->left, v);
    else if(current_node->key < v) return findElement(current_node->right,v);
}


void inOrder(Node current_node){
    if(current_node == NIL) return;
    inOrder(current_node->left);
    printf(" %d",current_node->key);
    inOrder(current_node->right);
}

void preOrder(Node current_node){
    printf(" %d",current_node->key);
    if(current_node->left != NIL)        preOrder(current_node->left);
    if (current_node->right != NIL) preOrder(current_node->right);
}


int main(){
    int num_query;
    char command[20];
    Node root = NIL;
    
    int key,priority;
    scanf("%d",&num_query);
    for(int i = 0;i < num_query;i++){
        scanf("%s",command);
        if(command[0] == 'i'){
            scanf("%d %d",&key,&priority);
            root = insert(root,key,priority);
        }else if(command[0] == 'f'){
            scanf("%d",&key);
            if(findElement(root,key)!=NIL) printf("yes\n");
            else printf("no\n");
        }else if(command[0] == 'p'){
            inOrder(root);printf("\n");
            preOrder(root);printf("\n");
        }else if(command[0] == 'd'){
            scanf("%d",&key);
            root = delete_(root,key);
        }
    }
    return 0;   
}

