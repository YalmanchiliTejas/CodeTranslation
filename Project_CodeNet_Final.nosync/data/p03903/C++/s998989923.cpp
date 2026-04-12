#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 4005;

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return x < e.x;
	}
};

int n, m;
vector<pi> gph[MAXN];
vector<edg> ed;
int dep[MAXN], par[12][MAXN], pva[12][MAXN];

void dfs(int x, int p){
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		par[0][i.second] = x;
		pva[0][i.second] = i.first;
		dep[i.second] = dep[x] + 1;
		dfs(i.second, x);
	}
}

int get(int s, int e){
	if(dep[e] < dep[s]) swap(s, e);
	int dx = dep[e] - dep[s];
	int ans = 0;
	for(int i=0; i<12; i++){
		if((dx >> i) & 1){
			ans = max(ans, pva[i][e]);
			e = par[i][e];
		}
	}
	for(int i=11; i>=0; i--){
		if(par[i][s] != par[i][e]){
			ans = max({ans, pva[i][s], pva[i][e]});
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e){
		ans = max({ans, pva[0][s], pva[0][e]});
	}
	return ans;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		ed.push_back({s, e, x});
	}
	sort(ed.begin(), ed.end());
	lint ans = 0;
	disj.init(n);
	for(auto &i : ed){
		if(disj.uni(i.s, i.e)){
			ans += i.x;
			gph[i.s].push_back(pi(i.x, i.e));
			gph[i.e].push_back(pi(i.x, i.s));
		}
	}
	dfs(1, 0);
	for(int i=1; i<12; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
			pva[i][j] = max(pva[i-1][j], pva[i-1][par[i-1][j]]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int s, e;
		scanf("%d %d",&s,&e);
		printf("%lld\n", ans - get(s, e));
	}
}
