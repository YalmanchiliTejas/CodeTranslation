#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll mod_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1LL)res=res*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return res;
}
ll h[105];
ll h_min[205];
ll h_dif[205];
int l[205],r[205];
int w[205];
int siz;
vector<int> G[205];
ll dp1[205],dp2[205];

void build(int lx,int rx){
	l[siz]=lx;
	r[siz]=rx;
	h_min[siz]=h[lx];
	w[siz]=rx-lx;
	for(int i=lx;i<rx;i++){
		h_min[siz]=min(h_min[siz],h[i]);
	}
	h_dif[siz]+=h_min[siz];
	int par=siz;
	int prv=lx;
	for(int i=lx;i<rx;i++){
		if(h[i]==h_min[par]){
			if(i==prv){
				prv++;
			}else{
				siz++;
				G[par].push_back(siz);
				h_dif[siz]-=h_min[par];
				w[par]-=i-prv;
				build(prv,i);
				prv=i+1;
			}
		}
	}
	if(prv!=rx){
		siz++;
		G[par].push_back(siz);
		h_dif[siz]-=h_min[par];
		w[par]-=rx-prv;
		build(prv,rx);
	}
}

void solve(int v){
	if(h_dif[v]==0)w[v]=0;
	dp1[v]=1;
	dp2[v]=1;
	for(int i=0;i<G[v].size();i++){
		solve(G[v][i]);
		dp1[v]*=dp1[G[v][i]];
		dp1[v]%=MOD;
		dp2[v]*=(dp1[G[v][i]]+dp2[G[v][i]])%MOD;
		dp2[v]%=MOD;
	}
	dp2[v]=dp2[v]*mod_pow(2,w[v])%MOD;
	if(h_dif[v]>0)dp2[v]+=dp1[v]*(mod_pow(2,h_dif[v])-2)%MOD;
	dp2[v]%=MOD;
	if(dp2[v]<0)dp2[v]+=MOD;
	dp1[v]*=mod_pow(2,h_dif[v]);
	dp1[v]%=MOD;
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&h[i]);
	}
	build(0,n);
	solve(0);
	printf("%lld\n",dp2[0]);
	return 0;
}