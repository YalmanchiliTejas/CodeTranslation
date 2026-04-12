#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Node{
    int key, pri;
    Node *left, *right;
    Node(const int& k, const int& p): key(k), pri(p), left(NULL), right(NULL) {}
};

Node* rightRotate(Node* n){
    Node* t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}

Node* leftRotate(Node* n){
    Node* t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}

Node* insert(Node* n, const int& k, const int& p){
    if(!n)
        return new Node(k, p);
    if(k == n->key) return n;
    if(k < n->key){
        n->left = insert(n->left, k, p);
        if(n->left->pri > n->pri)
            n = rightRotate(n);
    }
    if(k > n->key){
        n->right = insert(n->right, k, p);
        if(n->right->pri > n->pri)
            n = leftRotate(n);
    }
    return n;
}

Node* _del(Node* n, const int& k);

Node* del(Node* n, const int& k){
    if(!n) return NULL;
    if(k < n->key)
        n->left = del(n->left, k);
    else if(k > n->key)
        n->right = del(n->right, k);
    else{
        return _del(n, k); 
    }
    return n;
}

Node* _del(Node* n, const int& k){
    if(!(n->left) && !(n->right))
        return NULL;
    else if(!(n->left))
        n = leftRotate(n);
    else if(!(n->right))
        n = rightRotate(n);
    else if(n->left->pri > n->right->pri)
        n = rightRotate(n);
    else n = leftRotate(n);
    return del(n, k);
}

bool find(Node *n, const int& k){
    if(!n) return false;
    if(k == n->key) return true;
    if(k < n->key) return find(n->left, k);
    else return find(n->right, k);
}

void inOrder(Node* n){
    if(!n) return;
    inOrder(n->left);
    printf(" %d", n->key);
    inOrder(n->right);
}

void preOrder(Node* n){
    if(!n) return;
    printf(" %d", n->key);
    preOrder(n->left);
    preOrder(n->right);
}

void print(Node* n){
    inOrder(n);
    printf("\n");
    preOrder(n);
    printf("\n");
}

int main(){
    int n, x, y;
    char cmd[10];
    Node* root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%9s", cmd);
        if(strcmp(cmd, "insert") == 0){
            scanf("%d %d", &x, &y);
            root = insert(root, x, y);
        }
        else if(strcmp(cmd, "delete") == 0){
            scanf("%d", &x);
            root = del(root, x);
        }
        else if(strcmp(cmd, "print") == 0){
            print(root);            
        }
        else if(strcmp(cmd, "find") == 0){
            scanf("%d", &x);
            printf(find(root, x)? "yes\n" : "no\n");
        }
        else{
            printf("Invalid cmd\n");
        }
    }
}

