#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100010 ;
const int MOD = 1000000007;
const int LOG = 20;

int n, h[N], par[N], act[N];
vi G[N];

void DFS(int v, int p = 0){
	for (auto u:G[v]){
		if (u == p) continue;
		h[u] = h[v] + 1;
		par[u] = v;
		act[v] ++;
		DFS(u, v);
	}
}


int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u);
		G[u].pb(v);
	}
	if (n == 2) return cout << "Second", 0;
	if (n % 2 == 1){
		cout << "First";
		return 0;
	}
	for (int i = 1; i <= n; i++){
		if (G[i].size() == 1){
			DFS(i);
			break;
		}
	}
	set<pii> st;
	for (int i = 1; i <= n; i++){
		st.insert({-h[i], i});
	}
	while (st.size()){
		int fr = st.begin()->S;
		int v = par[fr];
		if (act[v] > 1) return cout << "First", 0;
		act[par[v]] --;
		st.erase({-h[v], v});
		st.erase({-h[fr], fr});
	}
	cout << "Second";
	return 0;
}
