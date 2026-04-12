#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
#include <map>
#include <cstring>
#include <cassert>
#include <random>
 
using namespace std;

const int INF = 1<<29;
 
struct RBST_node{
    int val,ma,mi,size; //値，最小，最大，部分木サイズ
    RBST_node *l_child,*r_child;
     
    RBST_node(int v){
        val=ma=mi=v;
        size=1;
        l_child=r_child=NULL;
    }
};
typedef pair<RBST_node*, RBST_node*> P;
 
RBST_node* update(RBST_node* t){
    t->size = 1;
    t->ma = t->mi = t->val;
    if(t->l_child){
        t->size += t->l_child->size;
        t->ma = min(t->ma,t->l_child->ma);
        t->mi = min(t->mi,t->l_child->mi);
    }
    if(t->r_child){
        t->size += t->r_child->size;
        t->ma = min(t->ma,t->r_child->ma);
        t->mi = min(t->mi,t->r_child->mi);
    }
    return t;
}
 
RBST_node* merge(RBST_node* t1, RBST_node* t2){
    if(!t1) return t2;
    if(!t2) return t1;
     
    int m=t1->size, n=t2->size;
    if(rand() % (m+n) < m){
        t1->r_child = merge(t1->r_child,t2);
        return update(t1);
    }else{
        t2->l_child = merge(t1,t2->l_child);
        return update(t2);      
    }
}
 
int node_size(RBST_node* t){
    if(!t) return 0;
    else return t->size;
}
 
//[,pos) [pos,)のペアに分ける
P split(RBST_node* t,int pos){
    if(!t) return P(NULL,NULL);
    if(node_size(t->l_child)<pos){
        P tmp = split(t->r_child,pos-node_size(t->l_child)-1);
        t->r_child = tmp.first;
        return P(update(t),tmp.second);
    }else{
        P tmp = split(t->l_child,pos);
        t->l_child = tmp.second;
        return P(tmp.first,update(t));
    }
}
 
int lower_bound(RBST_node *t, int val){
    if(!t) return 0;
    if(t->val>val) return lower_bound(t->l_child,val);
    else if(t->val==val) return node_size(t->l_child);
    else return node_size(t->l_child)+1+lower_bound(t->r_child,val);
}
 
RBST_node* insert(RBST_node* t,int val,int pos){
    RBST_node *p = new RBST_node(val);
    P tmp = split(t,pos);
    RBST_node *l = merge(tmp.first,p),*r=tmp.second;
    return merge(l,r); 
}
 
//left:小, right:大 として適切な場所にinsert
RBST_node* insert(RBST_node* t,int val){
    int pos=lower_bound(t,val);
    return insert(t,val,pos);
}
 
RBST_node* erase(RBST_node *t,int pos){
    P tmp = split(t,pos);
    RBST_node *l =tmp.first;
    RBST_node *r = split(tmp.second,1).second;
    return merge(l,r);
}
 
int kth_min(RBST_node *t, int k){
    int cnt=node_size(t->l_child);
    if(cnt==k) return t->val;
    else if(cnt>k) return kth_min(t->l_child,k);
    else return kth_min(t->r_child,k-cnt-1);
}
 

 
int main(void){

    srand(time(NULL));
    RBST_node *root=NULL;

    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i], root=insert(root,x[i]);

    for(int i=0;i<n;i++){
        root=erase(root,lower_bound(root,x[i]));
        cout<<kth_min(root,(n-1)/2)<<endl;
        root=insert(root,x[i]);
    }
 
    return 0;
 
}