#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

struct Node{
    int key;
    int priority;
    Node* parent;
    Node* left;
    Node* right;
    Node(){parent=left=right=NULL;}
    Node(int a, int b) :key(a),priority(b)
        {parent=left=right=NULL;} 
};

Node *root;

Node* rightRotate(Node* t){
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    if(t==root){    //根を更新
        root = s;
    }
    return s;
}

Node* leftRotate(Node* t){
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    if(t==root){    //根を更新
        root = s;
    }
    return s;
}

Node* insert_2(Node* t, int _key, int _priority){

    //葉に到達したら新しい節点を生成
    if(t==NULL) return new Node(_key, _priority);    //なるほど！！
    if(_key==t->key) return t;

    if(_key < t->key){
        t->left = insert_2(t->left, _key, _priority);
        if(t->priority < t->left->priority){
            t = rightRotate(t);
        }
    }else{
        t->right = insert_2(t->right, _key, _priority);
        if(t->priority < t->right->priority){
            t = leftRotate(t);
        }
    }
    return t;   //結局自分自身を返すためrootがそのまま帰ってくる
}

Node* _Delete(Node* t, int key);

Node* Delete(Node* t, int key){
    if(t==NULL) return NULL;

    //削除対象を検索
    if(key < t->key){
        t->left = Delete(t->left, key);
    }else if(key > t->key){
        t->right = Delete(t->right, key);
    }else{
        return _Delete(t, key);
    }
    //一致する節点が見つからまかった
    return t;
}

//削除対象の節点の場合
Node* _Delete(Node* t, int key){
    if((t->left==NULL)&&(t->right==NULL)) return NULL;  //葉の場合
    else if(t->left == NULL){   //右の子のみを持つ場合
        t = leftRotate(t);
    }else if(t->right == NULL){  //左の子のみを持つ場合
        t = rightRotate(t);
    }else{  //右の子と左の子を両方持つ場合
        if(t->left->priority > t->right->priority){
            t = rightRotate(t);
        }else{
            t = leftRotate(t);
        }
    }
    return Delete(t, key);
}

Node* find(Node* t, int key){
    while((t!=NULL)&&(t->key!=key)){    //終了条件
        if(key < t->key){
            t = t->left;
        }else{
            t = t->right;
        }
    }
    //キーが一致する節点見つけたらループを向けている
    return t;
}

void preParse(Node* u){
    if(u==NULL) return;
    preParse(u->left);
    printf(" %d", u->key);
    preParse(u->right);
}

void inParse(Node* u){
    if(u==NULL) return;
    printf(" %d", u->key);
    inParse(u->left);
    inParse(u->right);
}

int main(){

    int n;
    scanf("%d", &n);

    root = NULL;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(str == "insert"){
            int key, priority;
            scanf("%d %d", &key, &priority);
            root = insert_2(root, key, priority);   //新しい根を返す
        }else if(str == "delete"){
            int key;
            scanf("%d", &key);
            root = Delete(root, key);   //新しい根を返す
        }else if(str == "print"){
            preParse(root);
            printf("\n");
            inParse(root);
            printf("\n");
        }else if(str == "find"){
            int key;
            scanf("%d", &key);
            Node* u = find(root, key);
            if(u != NULL) printf("yes\n");
            else printf("no\n");
        }
    }

    return 0;
}
