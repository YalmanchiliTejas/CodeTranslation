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

int n,m;
vvi g;
vi a;

void dfs(int v){
	a[v]++;
	for(auto u:g[v]) if(!a[u]) dfs(u);
}

int main(){
	while(1){
		cin>>n>>m;
		if(!n) break;
		g=vvi(n);
		a=vi(n);
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int t=1;
		for(int i=0;i<n;i++) if(!a[i]) dfs(i),(t*=2)%=mod;
		cout<<t+(m?1:0)<<endl;
	}
}
