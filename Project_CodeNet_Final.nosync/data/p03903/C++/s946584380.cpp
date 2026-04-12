#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_V 5000
#define ll long long
using namespace std;

ll par[MAX_V],ran[MAX_V];
void init(int n){
	for(int i=0;i<n;i++){
		par[i] = i;
		ran[i] = i;
	}
}

ll find(ll x){
	if(par[x]==x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(ll x, ll y){
	x = find(x);
	y = find(y);
	if(x==y) return;
	if(ran[x]<ran[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(ran[x]==ran[y]) ran[x]++;
	}
}

bool same(ll x, ll y){
	return find(x)==find(y);
}

struct edge{ll u,v,cost;};
ll n,m;
vector<edge> E;
vector<edge> G[MAX_V];

bool comp(const edge& e1, const edge& e2){
	return e1.cost<e2.cost;
}

ll kruscal(){
	sort(E.begin(),E.end(),comp);
	init(n);
	long long res = 0;
	for(int i=0;i<E.size();i++){
		edge e = E[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res += e.cost;
			G[e.u].push_back({e.u,e.v,e.cost});
			G[e.v].push_back({e.v,e.u,e.cost});
		}
	}
	return res;
}

bool used[MAX_V];
ll d[MAX_V];
ll x[MAX_V][MAX_V];
void dfs(int s){
	used[s] = true;
	for(int i=0;i<G[s].size();i++){
		edge e = G[s][i];
		if(!used[e.v]){
			d[e.v] = max(d[s],e.cost);
			dfs(e.v);
		}
	}
}

int main(){
	int i,j;
	cin >> n >> m;
	for(i=0;i<m;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		a--; b--;
		edge e;
		e.u = a; e.v = b; e.cost = c;
		E.push_back(e);
	}
	
	ll res = kruscal();
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			used[j] = false;
			d[j] = 0;
		}
		dfs(i);
		for(j=0;j<n;j++){
			x[i][j] = d[j];
		}
	}
	int q;
	cin >> q;
	for(i=0;i<q;i++){
		int s,t;
		cin >> s >> t;
		s--; t--;
		cout << res - x[s][t] << endl;
	}
}
