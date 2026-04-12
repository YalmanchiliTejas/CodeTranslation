#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vvi g;
vi dp,DP;

void dfs(int v,int p){
	vi a,b;
	for(auto u:g[v]) if(u!=p){
		dfs(u,v);
		a.push_back(dp[u]);
		b.push_back(DP[u]);
	}
	int N=a.size(),S=0;
	bool B=1,t=1;
	for(auto i:a){
		B&=i;
		if(i) S++;
	}
	DP[v]=B;
	B=0;
	for(int i=0;i<N;i++) if(b[i]) B=1;
	if(S!=N-1) B=0;
	dp[v]=B;
}

int main(){
	cin>>n;
	g=vvi(n);
	dp=DP=vi(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,-1);
	if(dp[0]) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}