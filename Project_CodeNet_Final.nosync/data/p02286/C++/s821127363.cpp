#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct Node{
    int key, pri;
    Node *left,*right;
} *root,*NIL;

Node* leftRotate(Node *t){
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    if( t == root ) root = s;
    return s;
}

Node* rightRotate(Node *t){
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    if( t == root ) root = s;
    return s;
}

void inorder(Node *t){
    if( t == NIL ) return;
    inorder(t->left);
    cout << " " << t->key;
    inorder(t->right);
}

void preorder(Node *t){
    if( t == NIL ) return;
    cout << " " << t->key;
    preorder(t->left);
    preorder(t->right);
}

Node* insert(Node* t, int key, int pri){
    if( t == NIL ){
        Node *u = new Node();
        u->key = key;
        u->pri = pri;
        u->left = u->right = NIL;
        return u;
    }
    if( key == t->key ) return t;
    else if( key < t->key ){
        t->left = insert(t->left,key,pri);
        if(t->pri < t->left->pri)
            t = rightRotate(t);
    }
    else if( key > t->key ){
        t->right = insert(t->right,key,pri);
        if(t->pri < t->right->pri)
            t = leftRotate(t);
    }
    return t;
}

Node* find(Node* t,int key){
    if( t == NIL ) return NIL;
    if( key == t->key ) return t;
    else if( key < t->key ) return find(t->left,key);
    else return find(t->right,key);
}

Node* _delete(Node *t,int key);

Node* nodeDelete( Node* t,int key){
    if( t == NIL ) return NIL;
    if( key < t->key ) t->left = nodeDelete(t->left,key);
    else if( key > t->key ) t->right = nodeDelete(t->right,key);
    else return _delete(t,key);
    return t;
}

Node* _delete(Node* t,int key){
    if( t->left == NIL && t->right ==NIL ) return NIL;
    else if( t->right == NIL ){
        t = rightRotate(t);
    }
    else if( t->left == NIL ){
        t = leftRotate(t);
    }
    else {
        if( t->left->pri > t->right->pri ){
            t = rightRotate(t);
        }
        else t = leftRotate(t);
    }
    return nodeDelete(t,key);
}

int main(){
    int i,n,j,k,p;
    string s;

    NIL = new Node();
    NIL->left = NIL->right =NIL;
    root = NIL;

    cin >> n;
    while(n--){
        cin >> s;
        if( s == "insert" ){
            cin >> k >> p;
            Node* t = insert(root,k,p);
            if( root == NIL ) root = t;
        }
        else if( s == "find" ){
            cin >> k;
            if( find(root,k) != NIL ) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if( s == "delete" ){
            cin >> k;
            nodeDelete(root,k);
        }
        else if( s == "print" ){
            inorder(root);
            cout << endl;
            preorder(root);
            cout <<endl;
        }
    }
}

