#include<iostream>
#include<string>
using namespace std;
 
struct node{
  node* right;
  node* left;
  int key,priority;
};
 
 
node* rightRotate(node* t) {
    node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}
 
node* leftRotate(node* t) {
    node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}
 
node* insert(node* t, int key, int priority) {
    if(t == NULL) {
        node* t = new node;
        t->left=NULL; t->right = NULL;
        t->key = key; t->priority = priority;
        return t;
    }
    if(key == t->key) return t;
 
    if(key < t->key) {
        t->left = insert(t->left, key, priority);
        if(t->priority < t->left->priority) t = rightRotate(t);
    }
    else {
        t->right = insert(t->right, key, priority);
        if(t->priority < t->right->priority) t = leftRotate(t);
    }
    return t;
}
 
node* erase(node* t, int key){
    if(t == NULL) 
    return NULL;
 
    if(key == t->key) {
        if(t->left == NULL && t->right == NULL) return NULL;
        else if(t->left == NULL) t = leftRotate(t);
        else if(t->right == NULL) t = rightRotate(t);
        else {
            if(t->left->priority > t->right->priority) t = rightRotate(t);
            else t = leftRotate(t);
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
 
void tinorder(node* t) {
    if(t==NULL) return;
    tinorder(t->left);
    cout << " " << t->key;
    tinorder(t->right);
}
 
void pinorder(node* t) {
    if(t == NULL) return;
    cout << " " << t->key;
    pinorder(t->left);
    pinorder(t->right);
}
 
int main() {
    node* root=NULL;
    int n,key,priority;
    string s;
 
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s == "insert") {
            cin >> key >> priority;
            root = insert(root, key, priority);
        }
                else if(s == "find") {
            cin >> key;
            find(root, key);
        }
        else if(s == "delete") {
            cin >> key;
            root = erase(root, key);
        }
        else {
            tinorder(root);
            cout << endl;
            pinorder(root);
            cout << endl;
        }
    }
    return 0;
}
