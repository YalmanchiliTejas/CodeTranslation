#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct Node{
    int key;
    int priority;
    Node *parent;
    Node *lhs, *rhs;
} Node;

typedef struct{
    Node *root;
} BinaryTree;

void init_node(Node *node, int val, int pri){
    node->key = val;
    node->priority = pri;
    node->parent = nullptr;
    node->lhs = nullptr;
    node->rhs = nullptr;
}

void right_rotate(BinaryTree *T, Node *r){
    Node *l = r->lhs;
    if(l==nullptr || r==nullptr) return;
    if(T->root == r) T->root = l;
    if(r->parent != nullptr){
        if(r->key < r->parent->key) r->parent->lhs = l;
        else r->parent->rhs = l;
    }
    r->lhs = l->rhs;
    if(l->rhs != nullptr) l->rhs->parent = r;
    l->rhs = r;
    l->parent = r->parent;
    r->parent = l;
}

void left_rotate(BinaryTree *T, Node *l){
    Node *r = l->rhs;
    if(l==nullptr || r==nullptr) return;
    if(T->root == l) T->root = r;
    if(l->parent != nullptr){
        if(l->key < l->parent->key) l->parent->lhs = r;
        else l->parent->rhs = r;
    }
    l->rhs = r->lhs;
    if(r->lhs != nullptr) r->lhs->parent = l;
    r->lhs = l;
    r->parent = l->parent;
    l->parent = r;    
}

void init_bintree(BinaryTree *T){
    T->root = nullptr;
}

void insert(BinaryTree *T, Node *node){
    Node *parent = nullptr;
    Node *x = T->root;
    while(x != nullptr){
        parent = x;
        if(node->key < x->key) x = x->lhs;
        else x = x->rhs;
    }
    node->parent = parent;
    if(parent == nullptr) T->root = node;
    else if(node->key < parent->key) parent->lhs = node;
    else parent->rhs = node;
    
    while(node->parent != nullptr && node->priority > node->parent->priority){
        if(node->key < node->parent->key) right_rotate(T, node->parent);
        else left_rotate(T, node->parent);
    }
}

void print_preorder(Node *n){
    if(n == nullptr) return;
    cout << ' ' << n->key;
    print_preorder(n->lhs);
    print_preorder(n->rhs);
}

void print_inorder(Node *n){
    if(n == nullptr) return;
    print_inorder(n->lhs);
    cout << ' ' << n->key;
    print_inorder(n->rhs);
}

void print(BinaryTree *T){
    print_inorder(T->root);
    cout << endl;
    print_preorder(T->root);
    cout << endl;
}

void find(BinaryTree *T, int val){
    Node *n = T->root;
    while(n != nullptr){
        if(n->key == val){
            cout << "yes" << endl;
            return;
        }
        if(val < n->key) n = n->lhs;
        else n = n->rhs;
    }
    cout << "no" << endl;
    return;
}

Node *get_node(BinaryTree *T, int val){
    Node *n = T->root;
    while(n != nullptr){
        if(n->key == val) return n;
        if(val < n->key) n = n->lhs;
        else n = n->rhs;
    }
    return nullptr;
}

void del_node(BinaryTree *T, Node *n){
    if(n == nullptr) return;
    if(n->lhs == nullptr && n->rhs == nullptr){
        if(n->parent == nullptr) T->root = nullptr;
        else if(n->key < n->parent->key) n->parent->lhs = nullptr;
        else n->parent->rhs = nullptr;
        n = nullptr;
    }else if(n->lhs == nullptr || n->rhs == nullptr){
        if(n->lhs == nullptr) left_rotate(T, n);
        else right_rotate(T, n);
        del_node(T, n);
    }else{
        if(n->lhs->priority < n->rhs->priority) left_rotate(T, n);
        else right_rotate(T, n);
        del_node(T, n);
    }
}

void del(BinaryTree *T, int val){
    del_node(T, get_node(T, val));
}

BinaryTree T;
Node n[500000];

int main(){
    int idx = 0;
    int m, v, p;

    init_bintree(&T);
    cin >> m;
    for(int i=0;i<m;i++){
        string comm;
        cin >> comm;
        if(comm=="print") print(&T);
        else if(comm=="insert"){
            cin >> v >> p;
            init_node(n+idx, v, p);
            insert(&T, n+idx);
            idx++;
        }else if(comm=="find"){
            cin >> v;
            find(&T, v);
        }else if(comm=="delete"){
            cin >> v;
            del(&T, v);
        }
    }
    
    
    return 0;
}

