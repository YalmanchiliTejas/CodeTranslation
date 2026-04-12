#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<58;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

class Union_Find_Tree{
	public:
	vi Par;
	void Init(int n){
		Par=vi(n);
		for(int i=0;i<n;i++) Par[i]=i;
	}
	int Find_Par(int x){
		if(Par[x]==x) return x;
		return Par[x]=Find_Par(Par[x]);
	}
	bool Unite(int x,int y){
		x=Find_Par(x);
		y=Find_Par(y);
		if(x==y) return 0;
		Par[x]=y;
		return 1;
	}
	bool Same(int x,int y){
		return Find_Par(x)==Find_Par(y);
	}
};

class Graph{
	private:
	int V;
	vvi g;
	int lv=20;
	vi rank;
	vvi Par;
	void LCA_dfs(int v,int t){
		rank[v]=t;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i];
			if(rank[u]==-1){
				Par[0][u]=v;
				LCA_dfs(u,t+1);
			}
		}
	}
	void LCA_Prepare(){
		rank=vi(V,-1);
		Par=vvi(lv,vi(V));
		Par[0][0]=-1;
		LCA_dfs(0,0);
		for(int i=1;i<lv;i++) for(int j=0;j<V;j++){
			if(Par[i-1][j]<0) Par[i][j]=-1;
			else Par[i][j]=Par[i-1][Par[i-1][j]];
		}
	}
	int LCA(int s,int t){
		if(rank[s]>rank[t]) swap(s,t);
		for(int i=0;i<lv;i++) if((rank[t]-rank[s])>>i&1) t=Par[i][t];
		if(s==t) return s;
		for(int i=lv-1;i>=0;i--) if(Par[i][s]!=Par[i][t]){
			s=Par[i][s];
			t=Par[i][t];
		}
		return Par[0][s];
	}
	public:
	map<P,P> m;
	Union_Find_Tree uft;
	vl res;
	Graph(int v){
		V=v;
		g=vvi(v);
	}
	void add_edge(int s,int t){
		g[s].push_back(t);
		g[t].push_back(s);
	}
	void dfs(int v,int r,ll C,ll c){
		v=uft.Find_Par(v);
		if(rank[v]<=r) return;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i];
			if(rank[u]<rank[v]){
				dfs(u,r,C,c);
				P p=m[{min(u,v),max(u,v)}];
				ll I=p.first,cost=p.second;
				res[I]=C-cost+c;
				uft.Unite(v,u);
			}
		}
	}
	void solve(ll C,vip a,int E){
		res=vl(E,-1);
		LCA_Prepare();
		int S=a.size();
		uft.Init(V);
		for(int i=0;i<S;i++){
			P p=a[i].second;
			int u=p.first,v=p.second,c=a[i].first,r=rank[LCA(u,v)];
			res[m[{u,v}].first]=C;
			dfs(u,r,C,c);
			dfs(v,r,C,c);
		}
		for(int i=0;i<E;i++) cout<<res[i]<<endl;
	}
};

int n,m;

int main(){
	cin>>n>>m;
	Graph g(n);
	vip a(m);
	for(int i=0;i<m;i++){
		int s,t,c;
		cin>>s>>t>>c;
		s--;t--;
		if(s>t) swap(s,t);
		g.m[{s,t}]={i,c};
		a[i]={c,{s,t}};
	}
	sort(a.begin(),a.end());
	Union_Find_Tree uft;
	uft.Init(n);
	ll res=0;
	vip b;
	for(int i=0;i<m;i++){
		P p=a[i].second;
		int u=p.first,v=p.second,c=a[i].first;
		if(uft.Same(u,v)) b.push_back({c,{u,v}});
		else{
			res+=c;
			uft.Unite(u,v);
			g.add_edge(u,v);
		}
	}
	g.solve(res,b,m);
}