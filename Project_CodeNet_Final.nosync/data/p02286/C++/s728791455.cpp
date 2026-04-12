#include<iostream>
#include<string>
using namespace std;

struct node{
  node* right;
  node* left;
  int key,pri;
};

node* rightRotato(node* t) {
    node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

node* leftRotato(node* t) {
    node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

node* insert(node* t, int key, int pri) {
    if(t == NULL) {
        node* t = new node;
        t->left=NULL; t->right = NULL;
        t->key = key; t->pri = pri;
        return t;
    }
    if(key == t->key) return t;

    if(key < t->key) {
        t->left = insert(t->left, key, pri);
        if(t->pri < t->left->pri) t = rightRotato(t);
    }
    else {
        t->right = insert(t->right, key, pri);
        if(t->pri < t->right->pri) t = leftRotato(t);
    }
    return t;
}
node* erase(node* t, int key){
    if(t == NULL) return NULL;

    if(key == t->key) {
        if(t->left == NULL && t->right == NULL) return NULL;
        else if(t->left == NULL) t = leftRotato(t);
        else if(t->right == NULL) t = rightRotato(t);
        else {
            if(t->left->pri > t->right->pri) t = rightRotato(t);
            else t = leftRotato(t);
        }
        return erase(t,key);
    }
    if(key < t->key) t->left = erase(t->left, key);
    else t->right = erase(t->right, key);
    return t;
}

void find(node* t, int key) {
    while(t != NULL && key != t->key) {
        if(key < t->key) t = t->left;
        else t = t->right;
    }
    if(t == NULL) cout << "no" << endl;
    else cout << "yes" << endl;
}

void inorder(node* t) {
    if(t==NULL) return;
    inorder(t->left);
    cout << " " << t->key;
    inorder(t->right);
}

void preorder(node* t) {
    if(t == NULL) return;
    cout << " " << t->key;
    preorder(t->left);
    preorder(t->right);
}
int main() {
    node* root=NULL;
    int n,key,pri;
    string s;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s == "insert") {
            cin >> key >> pri;
            root = insert(root, key, pri);
        }
        else if(s == "delete") {
            cin >> key;
            root = erase(root, key);
        }
        else if(s == "find") {
            cin >> key;
            find(root, key);
        }
        else {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}

