#include <iostream>
using namespace std;

struct Node{
  int key,priority;
  Node *right,*left,*parent;
};

Node *root,*NIL;

Node* rightRotate(Node *t){
  Node *s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

Node* leftRotate(Node *t){
  Node *s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node* treeMinimum(Node *x){
    while(x->left != NIL) x = x->left;
    return x;
}

Node* find(Node *u,int k){
    while(u != NIL && k != u->key){
        if(k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

Node* treeSuccessor(Node *x){
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
}

Node* createNode(int key, int priority) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->priority = priority;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    return p;
}

Node* insert(Node *t, int key, int priority){
  if(t == NIL) return createNode(key, priority);
  if(key == t->key) return t;
  if(key < t->key){
    t->left = insert(t->left, key, priority);
    if(t->priority < t->left->priority) t = rightRotate(t);
  } else {
    t->right = insert(t->right, key, priority);
    if(t->priority < t->right->priority) t = leftRotate(t);
  }
  return t;
}

Node* _treeDelete(Node *t,int key);
Node* treeDelete(Node *t, int key);

Node* _treeDelete(Node *t,int key){
  if(t->left == NIL && t->right == NIL) return NIL;
  else if(t->left == NIL) t = leftRotate(t);
  else if(t->right == NIL) t = rightRotate(t);
  else{
    if(t->left->priority > t->right->priority) t = rightRotate(t);
    else t = leftRotate(t);
  }
  return treeDelete(t, key);
}

Node* treeDelete(Node *t, int key){
  if(t == NIL) return NIL;
  if(key < t->key) t->left = treeDelete(t->left, key);
  else if(key > t->key) t->right = treeDelete(t->right, key);
  else return _treeDelete(t, key);
  return t;
}

void inorder(Node *u){
    if(u==NIL) return;
    inorder(u->left);
    printf(" %d",u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u==NIL) return;
    printf(" %d",u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
  int n,i,x,y;
    string com;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        cin >> com;
        if(com=="find"){
            scanf("%d",&x);
            Node *t = find(root,x);
            if(t!=NIL) printf("yes\n");
            else printf("no\n");
        } else if(com=="insert"){
	  scanf("%d%d",&x,&y);
	  root=insert(root,x,y);
        } else if(com=="print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        } else if(com == "delete"){
            scanf("%d",&x);
            root=treeDelete(root,x);
        }
    }

    return 0;
}
