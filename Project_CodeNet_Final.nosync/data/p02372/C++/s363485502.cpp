#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
static const int MAX_N = 10000;

int n;
vector<pair<int, int> > G[MAX_N];
vector<pair<int, int> > va[MAX_N];
int memo[MAX_N], memo2[MAX_N];

void dfs(int pv, int v){
	va[v].push_back(make_pair(0, v));
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].first == pv) continue;
		dfs(v, G[v][i].first);
		memo[v] = max(memo[v], memo[G[v][i].first] + G[v][i].second);
		va[v].push_back(make_pair(memo[G[v][i].first] + G[v][i].second, G[v][i].first));
	}
}
void dfs2(int pv, int v){
	sort(va[v].begin(), va[v].end(), greater<pair<int, int> >());
	memo2[v] = max(memo2[v], va[v][0].first);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].first == pv) continue;
		if(va[v][0].second == G[v][i].first) va[G[v][i].first].push_back(make_pair(va[v][1].first + G[v][i].second, v));
		else va[G[v][i].first].push_back(make_pair(va[v][0].first + G[v][i].second, v));
		dfs2(v, G[v][i].first);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int s, t, w;
		scanf("%d %d %d", &s, &t, &w);
		G[s].push_back(make_pair(t, w));
		G[t].push_back(make_pair(s, w));
	}
	dfs(-1, 0);
	dfs2(-1, 0);
	for(int i = 0; i < n; i++) printf("%d\n", memo2[i]);
	return 0;
}


