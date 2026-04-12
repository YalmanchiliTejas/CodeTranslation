#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int n;
vector<int> g[10];
vector<bool> vi(10);
int ans = 0;

void dfs(int s, int cnt = 1) {
	if (cnt == n) {
		ans++;
	}
	vi[s] = true;
	for (auto& c : g[s]) {
		if (vi[c]) continue;
		vi[c] = true;
		dfs(c, cnt + 1);
		vi[c] = false;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}