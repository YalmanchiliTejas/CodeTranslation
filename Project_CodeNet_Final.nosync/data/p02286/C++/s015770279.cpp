#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
#define CLR(a)     memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)    cerr << #x << " = " << (x) << endl;//debug
#define debug(x)   cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define EPS        1e-10//sample:if((double)>=(double)+EPS)
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

using namespace std;

struct node {
  int key,priority;
  node *parent,*right, *left;
};
typedef node* nodep;
nodep root,NIL;

nodep rightRotate(nodep t){
  nodep s=t->left;
  t->left=s->right;
  s->right=t;
  return s;
}
nodep leftrotate(nodep t){
  nodep s=t->right;
  t->right=s->left;
  s->left=t;
  return s;
}
nodep insert(nodep t,int key,int priority){
  if(t==NIL){
    nodep n=(nodep)malloc(sizeof(node));
    n->key=key;
    n->priority=priority;
    n->left=NIL;
    n->right=NIL;
    return n;
  }
  if(key==t->key)return t;
  if(key<t->key){
    t->left=insert(t->left,key,priority);
    if(t->priority<t->left->priority)t=rightRotate(t);
  }
  else{
    t->right=insert(t->right,key,priority);
    if(t->priority<t->right->priority)t=leftrotate(t);
  }
  return t;
}
nodep _delete(nodep,int);
nodep deletetree(nodep t,int key){
  if(t==NIL)return NIL;
  if(key<t->key) t->left=deletetree(t->left,key);
  else if(key>t->key)t->right=deletetree(t->right,key);
  else return _delete(t,key);
  return t;
}
nodep _delete(nodep t,int key){
  if(t->left==NIL&&t->right==NIL)return NIL;
  else if(t->left==NIL)t=leftrotate(t);
  else if(t->right==NIL)t=rightRotate(t);
  else{
    if(t->left->priority>t->right->priority)t=rightRotate(t);
    else t=leftrotate(t);
  }
  return deletetree(t,key);
}
nodep find(nodep d,int key){
  while(d!=NIL&&d->key!=key){
    if(key<d->key)d=d->left;
    else d=d->right;
  }
  return d;
}
void inorder(nodep u){
  if(u==NIL)return;
  inorder(u->left);
  cout<<" "<<u->key;
  inorder(u->right);
}
void preorder(nodep u){
  if(u==NIL)return;
  cout<<" "<<u->key;
  preorder(u->left);
  preorder(u->right);
}
int main(){
  string buf;
  int a,n,b;
  cin>>n;
  rep(i,n){
    cin>>buf;
    if(buf[0]=='i'){
      cin>>a>>b;
      root=insert(root,a,b);
    }
    else if(buf[0]=='f'){
      cin>>a;
      if(find(root,a)==NIL)cout<<"no"<<endl;
      else cout<<"yes"<<endl;
    }
    else if(buf[0]=='d'){
      cin>>a;
      root=deletetree(root,a);
    }
    else{
      inorder(root);
      cout<<endl;
      preorder(root);
      cout<<endl;
    }
  }



  return 0;
}
