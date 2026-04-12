#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

struct UF{
	vector<int>par,sz;
	void init(int n){
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}
	int find(int x){
		return x==par[x]?x:par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		sz[x]+=sz[y];
		par[y]=x;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	int size(int x){
		return sz[find(x)];
	}
};

#define P2 pair<int,pair<int,int>>

signed main(){
	int N,M;
	cin>>N>>M;
	vector<int>a(M),b(M),c(M);
	priority_queue<P2,vector<P2>,greater<P2>>que;
	REP(i,M){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--;b[i]--;
		que.push({c[i],{a[i],b[i]}});
	}
	int weight = 0;
	UF uf;
	uf.init(N);
	vector<vector<pair<int,int>>>g(N);
	while(que.size()){
		int cost = que.top().first;
		int from = que.top().second.first;
		int to = que.top().second.second;
		que.pop();
		if(uf.same(from,to))continue;
		uf.unite(from,to);
		g[from].push_back({to,cost});
		g[to].push_back({from,cost});
		weight += cost;
	}

	int root = -1;
	vector<vector<int>>dist(N,vector<int>(N,0));
	auto dfs = [&](auto &&f,int now,int par,int ma)->void{
		CHMAX(dist[root][now],ma);
		for(auto e:g[now]){
			if(e.first == par)continue;
			f(f,e.first,now,max(ma,e.second));
		}
	};
	REP(i,N){
		root = i;
		dfs(dfs,i,-1,0);
	}
	int Q;
	cin>>Q;
	vector<int>ans;
	while(Q--){
		int s,t;
		cin>>s>>t;
		s--;t--;
		ans.push_back(dist[s][t]);
	}
	for(auto e:ans){
		cout<<weight - e<<endl;
	}
}