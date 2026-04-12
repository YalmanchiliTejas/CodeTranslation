#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define int long long
#define F first
#define S second
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;

// Bedone harf !

const int N = 10;
bool edge[N][N], mark[N];
int ans = 0, n, m, a[N];

bool check(){
	for(int i = 0; i < n - 1; i++)
		if(edge[a[i]][a[i + 1]] == false)
			return false;
	return true;
}

void solve(int id){
	if(id == n){
		ans += check();
//		if(check())
//			for(int i = 0; i < n; i++)
//				cout << a[i] << ' ';
//		cout << '\n';
		return;
	}
	for(int i = 2; i <= n; i++)
		if(mark[i] == false){
			mark[i] = true;
			a[id] = i;
			solve(id + 1);
			mark[i] = false;
		}
}

int32_t main(){
	ios::sync_with_stdio(false);cin.tie(0);	
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		edge[u][v] = true;
		edge[v][u] = true;
	}
	a[0] = 1;
	solve(1);
	cout << ans << '\n';
	return 0;
}