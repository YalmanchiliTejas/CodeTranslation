#include<iostream>
using namespace std;

struct Node{
    int key, priority;
    Node *left, *right;
};

Node *rightRotate(Node *t){
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s; 
}

Node *leftRotate(Node *t){
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s; 
}

Node *insert(Node *t, int key, int priority){
    if(t==NULL){
        Node *n = new Node();
        n->key = key;
        n->priority = priority;
        n->left = n->right = NULL;
        return n;
    } 
    if(t->key == key) return t; 
    
    if(t->key > key){
        t->left = insert(t->left, key, priority);
        if(t->priority < t->left->priority) t = rightRotate(t);
    }
    else{
        t->right = insert(t->right, key, priority);
        if(t->priority < t->right->priority) t = leftRotate(t);
    }
    return t;
}

Node *delNode(Node* t, int key);
Node *delSearch(Node *t, int key){
    if(t == NULL) return NULL;

    if(t->key > key) t->left = delSearch(t->left, key);
    else if(t->key < key) t->right = delSearch(t->right, key);
    else return delNode(t, key);
    return t;
}

Node *delNode(Node* t, int key){
    if(t->left == NULL && t->right == NULL) return NULL;
    else if(t->left == NULL) t = leftRotate(t);
    else if(t->right == NULL) t = rightRotate(t);
    else{
        if(t->left->priority > t->right->priority)
            t = rightRotate(t);
        else
            t = leftRotate(t);
    }
    return delSearch(t, key);
}


Node *find(Node* node, int key){
    while(node!=NULL && key!=node->key){
        if(key < node->key) node = node->left;
        else node = node->right;
        }
    return node;
}
void inorder(Node *u){
    if(u==NULL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}
void preorder(Node *u){
    if(u==NULL) return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}
void print(Node *root){
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
}



int main(){
    Node *root=NULL;
    int n,key,priority;
    string com;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> com;
        if(com == "print"){
            print(root);
        }
        else{
            cin >> key;
            if(com == "find"){
             Node *u = find(root, key);
             if(u != NULL) cout << "yes" << endl;
            else cout << "no" << endl;
            }  
            else if(com == "delete"){
            root = delSearch(root, key);
            }
            else if(com == "insert"){
            cin >> priority;
            root = insert(root, key, priority);
            }
        }
    }
    return 0;
}

