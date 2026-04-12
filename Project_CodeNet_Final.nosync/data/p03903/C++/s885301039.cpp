#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, P> Pll;
typedef pair<int, ll> Pl;

int par[4002];
int rk[4002];
 
void init(int n){
	for(int i=0; i<n; i++){
		par[i]=i;
	}
}
 
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
 
void unite(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rk[x]<rk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rk[x]==rk[y]) rk[x]++;
	}
}
 
bool same(int x, int y){
	return find(x)==find(y);
}

vector<Pl> g[4000];
ll mx[4000][4000];
bool used[4000];

void dfs(int s, int x){
	used[x]=1;
	for(int i=0; i<g[x].size(); i++){
		int y=g[x][i].first;
		if(used[y]) continue;
		mx[s][y]=max(mx[s][x], g[x][i].second);
		dfs(s, y);
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	vector<Pll> eg;
	for(int i=0; i<m; i++){
		int a, b; ll c;
		cin>>a>>b>>c;
		a--; b--;
		eg.push_back(Pll(c, P(a, b)));
	}
	sort(eg.begin(), eg.end());
	init(n);
	ll sum=0;
	int ct=0;
	for(int i=0; i<m; i++){
		int a=eg[i].second.first, b=eg[i].second.second;
		if(same(a, b)) continue;
		unite(a, b);
		ct++;
		ll c=eg[i].first;
		sum+=c;
		g[a].push_back(Pl(b, c));
		g[b].push_back(Pl(a, c));
		if(ct==n-1) break;
	}
	for(int i=0; i<n; i++){
		fill(used, used+n, 0);
		dfs(i, i);
	}
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		int s, t;
		cin>>s>>t;
		s--; t--;
		cout<<sum-mx[s][t]<<endl;
	}
    return 0;
}