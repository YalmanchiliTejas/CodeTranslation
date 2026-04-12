#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

struct node{
	int val;
	node*l,*r;
}dat[4000000];
node*root=&dat[0];
int p=1;

inline void update(node*t,int k,int x,int l,int r){
	if(r-l==1){
		t->val+=x;return;
	}
	if(k<(l+r)/2){
		if(t->l==NULL)t->l=&dat[p++];
		update(t->l,k,x,l,(l+r)/2);
		t->val=t->l->val+(t->r?t->r->val:0);
	}
	else{
		if(t->r==NULL)t->r=&dat[p++];
		update(t->r,k,x,(l+r)/2,r);
		t->val=(t->l?t->l->val:0)+t->r->val;
	}
}
inline int query(node*t,int a,int l,int r){
	if(r-l==1)return l;
	if(t->l&&t->l->val>=a)return query(t->l,a,l,(l+r)/2);
	else return query(t->r,a-(t->l?t->l->val:0),(l+r)/2,r);
}
int N=1<<30;
int a[400000];

int main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		update(root,a[i],1,0,N);
	}
	rep(i,n){
		update(root,a[i],-1,0,N);
		int A=n/2;
		printf("%d\n",query(root,A,0,N));
		update(root,a[i],1,0,N);
	}
}