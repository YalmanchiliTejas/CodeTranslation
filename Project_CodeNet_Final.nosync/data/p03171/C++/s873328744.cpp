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

ll dp[3005][5005];
int used[3005][3005];
vector<int> a;

ll dfs(int l, int r) {
	if (l == r) return 0;
	if (used[l][r]) return dp[l][r];
	used[l][r] = 1;
	ll res = -linf;
	maxs(res, a[l] - dfs(l + 1, r));
	maxs(res, a[r - 1] - dfs(l, r - 1));
	return dp[l][r] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	rep(i, n) cin >> a[i];
	cout << dfs(0, n) << endl;
	return 0;
}