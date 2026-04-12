#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MaxN = 3001;
const ll mod = 1000000007;
ll dp[MaxN][MaxN];

class Solver {
	int n; ll *a;
	ll* pre;
public :
    Solver() {
		solve();
	}
	void solve();
};

void Solver::solve() {
	//cout << "hello\n";
	cin >> n;

	a = new ll[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	pre = new ll[n + 1];
	pre[0] = 0;
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = pre[i] - pre[i - 1];
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n; i++) {
			int j = i + len - 1;
			if (j > n) break;
			ll sum = pre[j] - pre[i - 1];
			dp[i][j] = max(sum - dp[i][j - 1], sum - dp[i + 1][j]);
		}
	}
	
	cout << 2*dp[1][n] - pre[n] << "\n";
}

signed main() {
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/

    ll t=1;
    //cin >> t;
    while(t--) {
		Solver s;
	}
}
