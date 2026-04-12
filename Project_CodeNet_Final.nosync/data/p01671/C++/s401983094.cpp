#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;
typedef long long ll;

class UnionFind {
	vector<int>par, sz;
public:
	UnionFind() {}
	UnionFind(int n) {
		par = sz = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y)return;
		if (sz[x] > sz[y]) {
			par[y] = x;
			sz[x] += sz[y];
		}
		else {
			par[x] = y;
			sz[y] += sz[x];
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return sz[find(x)];
	}
};
struct st{int a,b,c,id;};

priority_queue<P,vector<P>,greater<P>>dat[200000];

void merge(int x,int y){
	if(dat[x].size()<dat[y].size()){
		swap(dat[x],dat[y]);
	}
	while(!dat[y].empty()){
		auto p=dat[y].top();dat[y].pop();
		dat[x].push(p);
	}
}

vector<P>E[200000],G[200000];
int ans[200000];
int in[200000],out[200000];
int cnt;

void dfs1(int v,int p){
	in[v]=cnt++;
	for(auto u:E[v]){
		if(u.second==p){
			continue;
		}
		dfs1(u.second,v);
	}
	out[v]=cnt;
}

void dfs(int v,int p){
	int id=-1;
	for(auto u:E[v]){
		if(u.second==p){
			id=u.first;
			continue;
		}
		dfs(u.second,v);
		merge(v,u.second);
	}
	for(auto u:G[v]){
		dat[v].push(u);
	}
	while(!dat[v].empty()&&in[v]<=in[dat[v].top().second]&&in[dat[v].top().second]<out[v]){
		dat[v].pop();
	}
	if(dat[v].empty()){
		ans[id]=INT_MAX;
	}
	else ans[id]=dat[v].top().first;
}

int w[200000];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	vector<st>v;
	rep(i,m){
		int a,b;scanf("%d%d%d",&a,&b,&w[i]);a--;b--;
		v.push_back({a,b,w[i],i});
	}
	sort(v.begin(),v.end(),[](st a,st b){return a.c<b.c;});
	UnionFind uf(n);
	ll sum=0;
	for(auto s:v){
		if(uf.same(s.a,s.b)){
			G[s.a].push_back(P(s.c,s.b));
			G[s.b].push_back(P(s.c,s.a));
			continue;
		}
		uf.unite(s.a,s.b);
		sum+=s.c;
		E[s.a].push_back(P(s.id,s.b));
		E[s.b].push_back(P(s.id,s.a));
	}
	if(uf.size(0)!=n){
		rep(i,m){
			puts("-1");
		}
		return 0;
	}
	memset(ans,-1,sizeof(ans));
	dfs1(0,-1);
	dfs(0,-1);
	rep(i,m){
		if(ans[i]==-1){
			printf("%lld\n",sum);
		}
		else{
			if(ans[i]==INT_MAX)puts("-1");
			else printf("%lld\n",sum-w[i]+ans[i]);
		}
	}
}
