#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll dat[800000],lazy[800000],N;
void init(int n){
	N=1;while(N<n)N<<=1;
	rep(i,2*N-1)dat[i]=0;
}
inline void push(int k){
	dat[k]+=lazy[k];
	if(k<N-1){
		lazy[k*2+1]+=lazy[k];
		lazy[k*2+2]+=lazy[k];
	}
	lazy[k]=0;
}
inline void upnode(int k){
	dat[k]=max(dat[k*2+1],dat[k*2+2]);
}
inline void update(int a,int b,ll x,int k=0,int l=0,int r=N){
	push(k);
	if(b<=l||r<=a)return;
	if(a<=l&&r<=b){
		lazy[k]+=x;
		push(k);
		return;
	}
	push(k);
	update(a,b,x,k*2+1,l,(l+r)/2);
	update(a,b,x,k*2+2,(l+r)/2,r);
	upnode(k);
}
inline ll query(int a,int b,int k=0,int l=0,int r=N){
	if(b<=l||r<=a)return -INF;
	if(a<=l&&r<=b){
		push(k);
		return dat[k];
	}
	push(k);
	ll lb=query(a,b,k*2+1,l,(l+r)/2);
	ll rb=query(a,b,k*2+2,(l+r)/2,r);
	upnode(k);
	return max(lb,rb);
}

vector<P>v[300000];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	rep(i,m){
		int l,r,a;scanf("%d%d%d",&l,&r,&a);l--;r--;
		v[r].push_back(P(l,a));
	}
	init(n);
	rep(i,n){
		if(i){
			update(i,i+1,max(0LL,query(0,i)));
		}
		for(auto p:v[i]){
			update(p.first,i+1,p.second);
		}
	}
	cout<<max(0LL,query(0,n))<<endl;
}