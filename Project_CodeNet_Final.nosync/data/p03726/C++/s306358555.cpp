#include <bits/stdc++.h>
const int MAX = 2e5 + 10;
typedef long long i64;
using namespace std;
int n;
int par[MAX];
int depth[MAX];
int ord[MAX];
vector<int> g[MAX];
void dfs(int v, int p = 0){
	par[v] = p;
	depth[v] = depth[p] + 1;
	for(auto nv: g[v]){
		if(nv == p)continue;
		dfs(nv, v);
	}
}
bool taken[MAX];
bool watched[MAX];
bool cmp(int a, int b){
	return depth[a] > depth[b];
}
int main() {

    #ifdef LOCAL_DEBUG
    freopen ("data.in", "r", stdin );
    freopen ("data.out", "w", stdout );
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'



    cin >> n;
    for(int i = 0; i < n - 1 ; i++){
    	int a, b; cin >> a >> b;
    	//a--, b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    dfs(1);
    bool ans = false;
    for(int i = 1; i <= n; i++)
    	ord[i] = i;
    sort(ord + 1, ord + n + 1, cmp);
    for(int i = 1; i <= n; i++){

    	int cur = ord[i];
    	//cout << cur << endl;
    	if(taken[cur])continue;
    	if(cur == 1)ans = true;
    	else{
    		if(taken[par[cur]])ans = true;
    		taken[par[cur]] = true;
    	}
    }

    cout << (ans ? "First" : "Second") << endl;

}

