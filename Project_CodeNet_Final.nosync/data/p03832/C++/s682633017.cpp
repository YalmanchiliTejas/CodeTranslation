/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=1005;
const int mod=1e9+7;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int mult(int x,int y){return 1LL*x*y%mod;}
int n,a,b,c,d;
int inv[maxn],g[maxn][maxn],ways[maxn][maxn];

class segtree{
public:
	int t[maxn*4],leaf[maxn];
	void build(int v,int l,int r){
		if(l==r){
			leaf[l]=v;
			return;
		}
		int mid=(l+r)>>1;
		build(v<<1,l,mid);
		build(v<<1|1,mid+1,r);
	}
	void update(int v,int l,int r,int vl,int vr,int val){
		if(l>vr||r<vl)return;
		if(l>=vl&&r<=vr){
//			cout<<l<<" "<<r<<" "<<val<<endl;
			t[v]=add(t[v],val);
			return;
		}
		int mid=(l+r)>>1;
		update(v<<1,l,mid,vl,vr,val);
		update(v<<1|1,mid+1,r,vl,vr,val);
	}
	int query(int v){
//		cout<<v<<" "<<leaf[v]<<endl;
		v=leaf[v];int res=0;
		for(;v;v>>=1)res=add(res,t[v]);
		return res;
	}
}T[maxn];
 
int main(){
	rep(i,1001)g[i][0]=1;
	REP(i,1000)REP(j,1000)g[i][j]=add(g[i-1][j],g[i-1][j-1]);
	inv[1]=1;
	for(int i=2;i<=1000;i++)inv[i]=(mod-mult(mod/i,inv[mod%i])+mod)%mod;
	for(int i=2;i<=1000;i++)inv[i]=mult(inv[i-1],inv[i]);
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	REP(i,n)REP(j,i)if(i%j==0){
		int res=1,cur=i;
		while(cur){
			res=mult(res,g[cur][j]);
			cur-=j;
		}
		ways[i][j]=mult(res,inv[i/j]);
//		cout<<i<<" "<<j<<" "<<ways[i][j]<<endl;
	}
	rep(i,n+1)T[i].build(1,a,b+1);
	T[0].update(1,a,b,a,b+1,1);
	rep(i,n)for(int j=a;j<=b;j++){
		int cur=T[i].query(j);
//		cout<<i<<" "<<j<<" "<<cur<<endl;
		for(int k=c;k<=d;k++){
			if(k*j>n-i)break;
			T[i+k*j].update(1,a,b+1,j+1,b+1,mult(g[n-i][k*j],mult(cur,ways[k*j][j])));
//			if(i+k*j==n)cout<<mult(g[n-i][k*j],mult(cur,ways[k*j][j]))<<endl;
		}
	}
	int ans=0;
	ans=add(ans,T[n].query(b+1));
	printf("%d",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/