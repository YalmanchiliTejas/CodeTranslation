#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=1e5;
struct edge{
	int u,v;
	ll c;
	edge(int u=-1,int v=-1,ll c=0):u(u),v(v),c(c){}
	bool operator <(const edge &e)const{
		return c<e.c;
	}
};
typedef pair<ll,int> P;
edge E[MAX_N<<1];
int N,M;
int par[MAX_N],ran[MAX_N];

int fpar(int v){
	if (v==par[v]){
		return v;
	}
	return par[v]=fpar(par[v]);
}
bool same(int u,int v){
	u=fpar(u);
	v=fpar(v);
	return u==v;
}
void unite(int u,int v){
	u=fpar(u);
	v=fpar(v);
	if (u!=v){
		if (ran[u]<ran[v]){
			par[u]=v;
		}else{
			par[v]=u;
			if (ran[u]==ran[v]){
				ran[u]++;
			}
		}
	}
}
int main(){
	cin>>N;
	M=0;
	{
		vector<P> vx,vy;
		REP(i,N){
			ll x,y;
			cin>>x>>y;
			vx.push_back(P(x,i));
			vy.push_back(P(y,i));
		}
		sort(vx.begin(),vx.end());
		sort(vy.begin(),vy.end());
		REP(i,N-1){
			E[M++]=edge(vx[i].second,vx[i+1].second,vx[i+1].first-vx[i].first);
			E[M++]=edge(vy[i].second,vy[i+1].second,vy[i+1].first-vy[i].first);
		}
		sort(E,E+M);
	}
	REP(v,N){
		par[v]=v;
		ran[v]=0;
	}
	ll ans=0;
	REP(i,M){
		edge e=E[i];
		if (!same(e.u,e.v)){
			unite(e.u,e.v);
			ans+=e.c;
		}
	}
	cout<<ans<<endl;
	return 0;
}