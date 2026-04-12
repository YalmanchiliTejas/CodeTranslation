#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct node{
    int key;
    int priority;
    struct node *parent;
    struct node *left;
    struct node *right;
};
typedef struct node * Node;
#define NIL NULL

Node root;
Node removeNode(Node t, int key);
Node deleteNode(Node t, int key);

Node rightRotate(Node t){
    Node l = t->left;
    t->left = l->right;
    l->right = t;
    
    return l;
}

Node leftRotate(Node t){
    Node r = t->right;
    t->right = r->left;
    r->left = t;
    
    return r;
}

Node insertNode(Node t, int key, int priority){
    if(t == NIL){
        Node n = (node *)malloc(sizeof(struct node));
        n->key = key;
        n->priority = priority;
        n->left = NIL;
        n->right = NIL;
        return n;
    }
    if(t->key == key) return t;
    
    if(t->key > key){
        t->left = insertNode(t->left, key, priority);
        if(t->priority < t->left->priority) t = rightRotate(t); 
    }
    else{
        t->right = insertNode(t->right, key, priority);
        if(t->priority < t->right->priority) t = leftRotate(t);
    }
    
    return t;
}

Node findNode(Node tree, int key){
    while(tree != NIL){
        if(tree-> key == key) return tree;
        else if(tree->key >= key) tree = tree->left;
        else tree = tree->right;
    }
    
    return tree;
}

Node treeMinimum(Node x){
    while(x->left != NIL) x = x->left;
    
    return x;
}

Node treeSuccessor(Node x){
    if(x->right != NIL) return treeMinimum(x->right);
    
    Node y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

Node deleteNode(Node t, int key){
    if(t == NIL) return NIL;
    
    if(key < t->key) t->left = deleteNode(t->left, key);
    else if(key > t->key) t->right = deleteNode(t->right, key);
    else return removeNode(t, key);
    
    return t;
}

Node removeNode(Node t, int key){
    if(t->left == NIL && t->right == NIL){
        return NIL;
    }
    else if(t->left == NIL) t = leftRotate(t);
    else if(t->right == NIL) t = rightRotate(t);
    else{
        if(t->left->priority > t->right->priority) t = rightRotate(t);
        else t = leftRotate(t);
    }
    
    return deleteNode(t, key);
}

void inorederNode(Node tree){
    if(tree->left != NIL) inorederNode(tree->left);
    cout << " " << tree->key;
    if(tree->right != NIL) inorederNode(tree->right);
}

void preorederNode(Node tree){
    cout << " " << tree->key;
    if(tree->left != NIL) preorederNode(tree->left);
    if(tree->right != NIL) preorederNode(tree->right);
}

int main(void){
    int n, key, priority;
    string command;
    Node t;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> command;
        
        if(command[0] == 'p'){
            inorederNode(root);
            cout << endl;
            preorederNode(root);
            cout << endl;
        }
        else if(command[0] == 'i'){
            cin >> key >> priority;
            root = insertNode(root, key, priority);
        }
        else if(command[0] == 'f'){
            cin >> key;
            t = findNode(root, key);
            if(t != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(command[0] == 'd'){
            cin >> key;
            root = deleteNode(root, key);
        }
    }
}

