#include<bits/stdc++.h>
#define inf 1<<29
#define linf (1e16)
#define eps (1e-8)
#define Eps (1e-12)
#define mod 1000000007
#define pi acos(-1.0)
#define phi (1.0+sqrt(5.0))/2.0
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define pd(a) printf("%.10f\n",(double)(a))
#define pld(a) printf("%.10Lf\n",(ld)(a))
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(a)-1;(b)<=i;i--)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define equals(a,b) (fabs((a)-(b))<eps)
#define track(); cout<<"#############"<<endl;
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

typedef struct node{
  struct node *l=NULL;
  struct node *r=NULL;
  int key=0;
  int pri=0;
}Node;

Node* RightRotate(Node *t){
  Node *s=t->l;
  t->l=s->r;
  s->r=t;
  return s;
}

Node* LeftRotate(Node *t){
  Node *s=t->r;
  t->r=s->l;
  s->l=t;
  return s;
}

Node* ins(Node* t,int key,int pri){
  if(t==NULL){
    t=(Node*)malloc(sizeof(Node));
    t->l=NULL;
    t->r=NULL;
    t->key=key;
    t->pri=pri;
    return t;
  }
  if(key==t->key)return t;
  if(key<t->key){
    t->l = ins(t->l,key,pri);
    if(t->pri < t->l->pri)t=RightRotate(t);
  }
  else {
    t->r = ins(t->r,key,pri);
    if(t->pri < t->r->pri)t=LeftRotate(t);
  }
  return t;
}

bool find(Node *t,int key){
  if(t==NULL)return false;
  if(t->key==key)return true;
  if(key<t->key)return find(t->l,key);
  return find(t->r,key);
}

Node* del(Node *t,int key){
  if(t==NULL)return NULL;
  if(key==t->key){
    if(t->l==NULL && t->r==NULL){
      return NULL;
    }
    else if(t->l==NULL){
      t=LeftRotate(t);
    }
    else if(t->r==NULL){
      t=RightRotate(t);
    }
    else {
      if(t->l->pri >t->r->pri)
        t=RightRotate(t);
      else 
        t=LeftRotate(t);
    }
    return del(t,key);
  }

  if(key<t->key)
    t->l = del(t->l,key);
  else 
    t->r = del(t->r,key);
  return t;
}

void inorder(node *t){
  if(t->l != NULL)inorder(t->l);
//  cout<<" "<<t->key;
  printf(" %d",t->key);
  if(t->r != NULL)inorder(t->r);
}

void preorder(node *t){
  printf(" %d",t->key);
  //cout<<" "<<t->key;
  if(t->l != NULL)preorder(t->l);
  if(t->r != NULL)preorder(t->r);
}

int main()
{
  int n,a,b;
  string s;
  Node *t=NULL;
  cin>>n;
  FOR(i,0,n){
    cin>>s;
    if(s=="insert"){
      cin>>a>>b;
      t=ins(t,a,b);
    }
    else if(s=="find"){
      cin>>a;
      if(find(t,a))cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
    else if(s=="delete"){
      cin>>a;
      t=del(t,a);
    }
    else {
      inorder(t);
      cout<<endl;
      preorder(t);
      cout<<endl;
    }
  }
  return 0;
}

