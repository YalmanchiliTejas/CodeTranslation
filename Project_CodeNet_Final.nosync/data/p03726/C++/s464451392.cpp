#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;
using namespace std;
 
const int MAXN = 100000 + 20, MAXM = 20, MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e9 + 10;
int a[MAXN], d[MAXN];
vector <int> vec[MAXN];
bool ok = 0;

void dfs(int u, int par) {
	int t = 1;
	int cnt = 0;
	for (int i = 0; i < vec[u].size(); i++) {
		if (vec[u][i] != par) {
			dfs(vec[u][i], u);
			t += d[vec[u][i]];	
			if (d[vec[u][i]] % 2 == 1)
				cnt++;
		}
	}	
	
	d[u] = t;
	if (cnt > 1)
		ok = 1;
}

void solve() {
	int n;
	cin >> n;
	
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	dfs(1, 0);
	
	if (n % 2 == 1)
		cout << "First" << endl;
	else if (ok == 1)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
		
		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}