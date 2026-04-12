#include<iostream>
#include<string>
using namespace std;

struct Node{
        int key, priority;
        Node *left, *right;
};

static Node *root;

Node* deletekey(Node* t, int key);
Node* _deletekey(Node* t, int key);

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

Node *insert(int v, int priority, Node *t){
        if(t==NULL){
                Node *a = new Node();
                a->key = v;
                a->priority = priority;
                a->left = NULL;
                a->right = NULL;
                return a;
        }
        if(v==t->key) return t;

        if(v<t->key){
                t->left = insert(v, priority, t->left);
                if(t->priority<t->left->priority)
                        t = rightRotate(t);
        }else{
                t->right = insert(v, priority, t->right);
                if(t->priority<t->right->priority)
                        t = leftRotate(t);
        }
        return t;
}

bool find(int v){
        Node *i = root;
        while(i!=NULL){
                if(v==i->key) return true;
                else if(v<i->key) i = i->left;
                else i = i->right;
        }
        return false;
}


Node* deletekey(Node* t, int key){
        if(!t) return NULL;
        if(key == t->key) return _deletekey(t, key);
        if(key < t->key) t->left = deletekey(t->left, key);
        else t->right = deletekey(t->right, key);
        return t;
}

Node* _deletekey(Node* t, int key){
        if(t->left==NULL&&t->right==NULL){
                delete t;
                return NULL;
        }else if(t->left == NULL)
                t = leftRotate(t);
        else if(t->right == NULL)
                t = rightRotate(t);
        else{
                if(t->left->priority > t->right->priority)
                        t = rightRotate(t);
                else
                        t = leftRotate(t);
        }
        return deletekey(t, key);
}

void print_preorder(Node *i){
        if(!i) return;
        cout<<" "<<i->key;
        print_preorder(i->left);
        print_preorder(i->right);
}

void print_inorder(Node *i){
        if(!i) return;
        print_inorder(i->left);
        cout<<" "<<i->key;
        print_inorder(i->right);
}

int main(){
        int n,v,u;
        string s;
        cin>>n;
        root = NULL;
        for(int i=0;i<n;i++){
                cin>>s;
                if(s=="insert") {
                        cin>>v>>u;
                        root = insert(v,u,root);
                }else if(s=="find"){
                        cin>>v;
                        if(find(v)) cout<<"yes"<<endl;
                        else cout<<"no"<<endl;
                }else if(s=="delete"){
                        cin>>v;
                        root = deletekey(root, v);
                }else if(s=="print"){
                        print_inorder(root);
                        cout<<endl;
                        print_preorder(root);
                        cout<<endl;
                }
        }
        return 0;
}
