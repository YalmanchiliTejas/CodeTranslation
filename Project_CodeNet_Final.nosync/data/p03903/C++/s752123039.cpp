#include <iostream>
#include <fstream>
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
const int inf=1<<30;
const ll INF=1ll<<57;
const double pi=acos(-1);
const double eps=1e-6;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,1,1,1,0},DY[8]={1,0,-1,-1,-1,0,1,1};

class Union_Find_Tree{
	public:
	vi Par,Rank;
	Union_Find_Tree(int n){
		Par=Rank=vi(n);
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
		if(Rank[x]<Rank[y]) Par[x]=y;
		else{
			Par[y]=x;
			if(Rank[x]==Rank[y]) Rank[x]++;
		}
		return 1;
	}
	bool Same(int x,int y){
		return Find_Par(x)==Find_Par(y);
	}
};

class Graph{
	private:
	int V;
	vvp List;
	vip e;
	vb used;
	void Rec(int v,int M,vl& d){
		used[v]=1;
		d[v]=M;
		for(int i=0;i<List[v].size();i++){
			int u=List[v][i].first,c=List[v][i].second;
			if(!used[u]) Rec(u,max(M,c),d);
		}
	}
	public:
	Graph(int v){
		V=v;
		List=vvp(v);
	}
	void add_edge(int s,int t,int c){
		List[s].push_back({t,c});
		List[t].push_back({s,c});
		e.push_back({c,{s,t}});
	}
	vvl func(){
		vvl d(V,vl(V));
		for(int i=0;i<V;i++){
			used=vb(V,0);
			Rec(i,0,d[i]);
		}
		return d;
	}
	void solve(){
		Union_Find_Tree uft(V);
		Graph G(V);
		ll cost=0;
		sort(e.begin(),e.end());
		for(int i=0;i<e.size();i++){
			ll c=e[i].first,s=e[i].second.first,t=e[i].second.second;
			if(!uft.Same(s,t)){
				uft.Unite(s,t);
				G.add_edge(s,t,c);
				cost+=c;
			}
		}
		vvl d=G.func();
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int s,t;
			cin>>s>>t;
			cout<<cost-d[s-1][t-1]<<endl;
		}
	}
};

int n,m;

int main(){
	cin>>n>>m;
	Graph g(n);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g.add_edge(a-1,b-1,c);
	}
	g.solve();
}