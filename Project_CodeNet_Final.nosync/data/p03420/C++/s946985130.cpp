#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		ll ans = (ll) n * n;
		cout << ans << endl;
		return 0;
	}

	ll ans = 0;
	for (int b = 1; b <= n; b++) {
		if (b <= k) continue;
		ll x = (n / b) * (b - k);
		ll y = max(0ll, (ll) n % b - k + 1);
		ans += x + y;
	}
	cout << ans << endl;
}