#include <iostream>
#include <string>
using namespace std;
struct T{
    int key,priority;
    T *parent,*left,*right;
};
    T *root=NULL;
T* rightRotate(T *t){
    T *s=t->left;
    t->left=s->right;
    s->right=t;
    if(t==root){
        root=s;
    }
    return s;
}
T* leftRotate(T *t){
    T *s=t->right;
    t->right=s->left;
    s->left=t;
    if(t==root){
        root=s;
    }
    return s;
}
T* insert(T *t,int key,int priority){
    if(t==NULL){
        T *r= new T();
        r->key=key;
        r->priority=priority;
        r->left=r->right=NULL;
        return r;
    }
    if(key==t->key){
        return t;
    }
    if(key < t->key){
        t->left=insert(t->left,key,priority);
        if(t->priority < t->left->priority){
            t=rightRotate(t);
        }
    }
    else{
        t->right=insert(t->right,key,priority);
        if(t->priority < t->right->priority){
            t=leftRotate(t);
        }
    }
    return t;
}
T* Tfind(T *x,int k){
    T *z=new T();
    *z={NULL};
    z->key=k;
    while(x!=NULL){
        if(z->key==x->key){
            return x;
        }
        if(z->key < x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    return NULL;
}
T* Tdelete(T *t, int key);
T* _delete(T *t,int key){
    if(t==NULL){
        return NULL;
    }
    if(key < t->key){
        t->left=_delete(t->left,key);
    }
    else if(key > t->key){
        t->right=_delete(t->right,key);
    }
    else{
        return Tdelete(t,key);
    }
    return t;
}
T* Tdelete(T *t,int key){
    if(t->left==NULL && t->right==NULL){
        return NULL;
    }
    else if(t->left==NULL){
        t=leftRotate(t);
    }
    else if(t->right==NULL){
        t=rightRotate(t);
    }
    else{
        if(t->left->priority > t->right->priority){
            t=rightRotate(t);
        }
        else{
            t=leftRotate(t);
        }
    }
    return _delete(t,key);
}
void Preorder(T *root){
    if(root!=NULL){
        cout<<" "<<root->key;
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Inorder(T *root){
    if(root!=NULL){
        Inorder(root->left);
        cout<<" "<<root->key;
        Inorder(root->right);
    }
}
int main(){
    int n,key,priority;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="insert"){
            cin>>key>>priority;
            T *t=insert(root,key,priority);
            if (root == NULL) {
				root = t;
			}
        }
        else if(s=="find"){
            cin>>key;
            if(Tfind(root,key)!=NULL){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
        else if(s=="delete"){
            cin>>key;
            _delete(root,key);
        }
        else{
            Inorder(root);
            cout<<endl;
            Preorder(root);
            cout<<endl;
        }
    }
    return 0;
}
