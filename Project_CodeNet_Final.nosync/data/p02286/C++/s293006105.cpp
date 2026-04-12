#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

struct Node{
    int k,p;
    Node *l,*r;
};

Node *root;

Node *rightRotate(Node *t){
    Node *s=t->l;
    t->l=s->r;
    s->r=t;
    return s;
}

Node *leftRotate(Node *t){
    Node *s=t->r;
    t->r=s->l;
    s->l=t;
    return s;
}

Node *insert(Node *t,int k,int p){
    if(t==NULL){
        t=(Node *)malloc(sizeof(Node));
        t->k=k;
        t->p=p;
        t->l=t->r=NULL;
        return t;
    }
    if(k==t->k)return t;
    if(k<t->k){
        t->l=insert(t->l,k,p);
        if(t->p<t->l->p)t=rightRotate(t);
    }
    else{
        t->r=insert(t->r,k,p);
        if(t->p<t->r->p)t=leftRotate(t);
    }
    return t;
}

Node *find(Node *v,int k){
    while(v!=NULL&&k!=v->k){
        if(k<v->k)v=v->l;
        else v=v->r;
    }
    return v;
}

Node *del(Node *t,int k){
    if(t==NULL)return NULL;
    if(k<t->k)t->l=del(t->l,k);
    else if(k>t->k)t->r=del(t->r,k);
    else{
        if(t->l==NULL&&t->r==NULL)return NULL;
        else if(t->l==NULL)t=leftRotate(t);
        else if(t->r==NULL)t=rightRotate(t);
        else{
            if(t->l->p>t->r->p)t=rightRotate(t);
            else t=leftRotate(t);
        }
        return del(t,k);
    }
    return t;
}

void inorder(Node* v){
    if(v==NULL)return;
    inorder(v->l);
    cout<<" "<<v->k;
    inorder(v->r);
}

void preorder(Node* v){
    if(v==NULL)return;
    cout<<" "<<v->k;
    preorder(v->l);
    preorder(v->r);
}

void run(){
    int n;
    cin>>n;
    rep(i,n){
       string s;
       cin>>s;
       if(s=="insert"){
           int k,p;
           cin>>k>>p;
           root=insert(root,k,p);
       }
       else if(s=="find"){
           int k;
           cin>>k;
           cout<<(find(root,k)!=NULL?"yes":"no")<<endl;
       }
       else if(s=="print"){
           inorder(root);
           cout<<endl;
           preorder(root);
           cout<<endl;
       }
       else{
           int k;
           cin>>k;
           root=del(root, k);
       }
   }
}

