#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

struct node{
	int val;
	node*l,*r;
}dat[4000000];
int p;

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
inline int query(node*t,int a,int b,int l,int r){
	if(b<=l||r<=a)return 0;
	if(a<=l&&r<=b)return t->val;
	int lb=(t->l?query(t->l,a,b,l,(l+r)/2):0);
	int rb=(t->r?query(t->r,a,b,(l+r)/2,r):0);
	return lb+rb;
}
int a[400000];
int main(){
	int n;scanf("%d",&n);
	node*root=&dat[p++];
	int N=1<<30;
	rep(i,n){
		scanf("%d",&a[i]);
		update(root,a[i],1,0,N);
	}
	rep(i,n){
		update(root,a[i],-1,0,N);
		int l=0,r=1000000000;
		int A=n/2;
		while(l!=r){
			int t=(l+r)/2;
			if(query(root,0,t+1,0,N)>=A)r=t;
			else l=t+1;
		}
		printf("%d\n",l);
		update(root,a[i],1,0,N);
	}
}