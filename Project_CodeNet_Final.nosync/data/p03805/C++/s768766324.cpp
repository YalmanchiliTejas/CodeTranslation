#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> g(10);
vector<bool> visited(10, false);
int ans = 0;
int n, m;

void dfs(vector<int> ARR, int s, int cnt) {
	visited[s] = true;
	if (cnt + 1 == n) {
		bool ok = true;
		rep (i, n) if (!visited[i]) ok = false;
		if (ok) ans++;
		return;
	}
	for (auto to: g[s]) {
		if (visited[to]) continue;
		if (to == ARR[cnt]) {
			dfs(ARR, to, cnt + 1);
		}
	}
}

int main(void) {

	cin >> n >> m;
	rep (i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	vector<int> arr(n - 1);
	rep (i, n - 1) arr[i] = i + 1;

	
	do {
		rep (i, n) visited[i] = false;
		dfs(arr, 0, 0);
	} while (next_permutation(rng(arr)));

	cout << ans << endl;
	return 0;
}
