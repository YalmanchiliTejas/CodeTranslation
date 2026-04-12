#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) (int)((a).size())
#define all(c) (c).begin(), (c).end()
#define debug(v) {for (auto z : v) {cerr << z << ' ';} cerr << endl;}

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const ll MOD = 1e9 + 7;
const ll INV = -1e18;
const int N = 2e5 + 5;

ll a[N], dp[N][3];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

	dp[0][0] = a[0];
	dp[0][1] = INV;
	dp[0][2] = INV;
	dp[1][0] = INV;
	dp[1][1] = a[1];
	dp[1][2] = INV;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (dp[i-2][j] == INV) dp[i][j] = INV;
			else dp[i][j] = dp[i-2][j] + a[i];
		}
		if (i == 2) dp[i][2] = a[i];
		else {
			for (int j = 1; j < 3; j++) {
				if (dp[i-3][j-1] != INV)
					dp[i][j] = max(dp[i][j], dp[i-3][j-1] + a[i]);
			}
		}
	}

	ll ans = 0;
	if (n % 2 == 0) {
		ans = max(dp[n-1][1], dp[n-2][0]);
	}
	else {
		ans = max(dp[n-1][2], dp[n-2][1]);
		ans = max(ans, dp[n-3][0]);
	}
	printf("%lld\n", ans);
}
