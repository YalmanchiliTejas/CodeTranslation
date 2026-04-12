#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

ll pw(ll n, ll a) {
	if (a == 0) return 1;
	else return n * pw(n, a - 1);
}

ll dfs(int n) {
	if (n == 0) return 1;
	else {
		ll t = dfs(n - 1);
		return 1 + t + 1 + t + 1;
	}
}

ll dfs2(int n, ll i) {
	if (n == 0) {
		return 1;
	}
	ll sum = dfs(n);
	if (i <= 1) return 0;
	else if (i < sum / 2 + 1) return dfs2(n-1, i-1);
	else if (i == sum / 2 + 1) return 1 + dfs2(n-1, i-2);
	else return (pow(2ll, (ll) n + 1) - 1) - dfs2(n, sum - i);
}

void solve() {
	int n;
	ll x;
	cin >> n >> x;
	cout << dfs2(n, x) << endl;
	
}

int main() {
	solve();
	return 0;
}