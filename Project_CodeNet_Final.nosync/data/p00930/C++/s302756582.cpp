#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class segtree{
public:
	static const int N=1<<19;
	int dp[1<<20];
	segtree(){
		memset(dp,0,sizeof(dp));
	}
	void update(int k,int v){
		k+=N-1;
		dp[k]=v;
		while(k>0){
			k=(k-1)/2;
			dp[k]=min(dp[k*2+1],dp[k*2+2]);
		}
	}

	int query(int a,int b,int k=0,int l=0,int r=N){
		if(b<=l || r<=a)return INF;
		if(a<=l && r<=b)return dp[k];
		int mid=(l+r)/2;
		int vl=query(a,b,k*2+1,l,mid);
		int vr=query(a,b,k*2+2,mid,r);
		return min(vl,vr);
	}
};

class rsegtree{
public:
	static const int N=1<<19;
	int dp[1<<20];
	int lazy[1<<20];
	rsegtree(){
		memset(dp,0,sizeof(dp));
	}

	void lazy_eval(int k){
		dp[k]+=lazy[k];
		if(k<N-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void lazy_upd(int k){
		dp[k]=min(dp[k*2+1],dp[k*2+2]);
	}

	void update(int a,int b,int v,int k=0,int l=0,int r=N){
		lazy_eval(k);
		if(b<=l || r<=a)return;
		if(a<=l && r<=b){
			lazy[k]+=v;
			lazy_eval(k);
			return;
		}
		int mid=(l+r)/2;
		update(a,b,v,k*2+1,l,mid);
		update(a,b,v,k*2+2,mid,r);
		lazy_upd(k);
	}

	int query(int a,int b,int k=0,int l=0,int r=N){
		lazy_eval(k);
		if(b<=l || r<=a)return INF;
		if(a<=l && r<=b)return dp[k];
		int mid=(l+r)/2;
		int vl=query(a,b,k*2+1,l,mid);
		int vr=query(a,b,k*2+2,mid,r);
		lazy_upd(k);
		return min(vl,vr);
	}
};

segtree seg;
rsegtree rseg;
int n,q;
string str;
int type[300005];

int main(void){
	scanf("%d%d",&n,&q);
	cin >> str;
	for(int i=0;i<n;i++){
		if(str[i]=='('){
			type[i]=1;
			seg.update(i,INF);
			rseg.update(i+1,n+1,1);
		}else{
			type[i]=-1;
			seg.update(i,i);
			rseg.update(i+1,n+1,-1);
		}
	}
	for(int i=0;i<q;i++){
		int a;
		scanf("%d",&a);
		a--;
		type[a]=-type[a];
		if(type[a]==-1){
			seg.update(a,a);
			rseg.update(a+1,n+1,-2);
			int v=seg.query(0,n);
			printf("%d\n",v+1);
			seg.update(v,INF);
			rseg.update(v+1,n+1,2);
			type[v]=-type[v];
		}else{
			seg.update(a,INF);
			rseg.update(a+1,n+1,2);
			int l=0,r=a+1;
			while(l+1<r){
				int mid=(l+r)/2;
				rseg.update(mid,n+1,-2);
				if(rseg.query(mid,n+1)>=0)r=mid;
				else l=mid;
				rseg.update(mid,n+1,2);
			}
			printf("%d\n",r);
			seg.update(r-1,r-1);
			rseg.update(r,n+1,-2);
			type[r-1]=-type[r-1];
		}
	}
	return 0;
}
