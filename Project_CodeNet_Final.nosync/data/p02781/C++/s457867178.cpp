#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
//const ll p = 1e9 + 7;
//const ll p = 998244353;
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	string n;
	ll k;
	cin >> n >> k;
	ll m = n.size();

	ll ans = pow(9, k);
	for (ll i = 0; i < k; i++) ans *= m - 1 - i;
	for (ll i = 0; i < k; i++) ans /= i + 1;

	vector<vector<vll>> dp(2, vector<vll>(m, vll(k + 1, 0)));
	dp[0][0][1] = n[0] - '0' - 1;
	dp[1][0][1] = 1;
	for (ll i = 1; i < m; i++) {
		for (ll j = 1; j <= k; j++) {
			dp[0][i][j] = dp[0][i - 1][j] + dp[0][i - 1][j - 1] * 9;
			if (n[i] != '0') {
				dp[0][i][j] += dp[1][i - 1][j];
				dp[0][i][j] += dp[1][i - 1][j - 1] * (n[i] - '0' - 1);
			}
			if (n[i] == '0') dp[1][i][j] = dp[1][i - 1][j];
			else dp[1][i][j] = dp[1][i - 1][j - 1];

			//cout << endl;
			//cout << 0 << " " << i + 1 << " " << j << " " << dp[0][i][j] << endl;
			//cout << 1 << " " << i + 1 << " " << j << " " << dp[1][i][j] << endl;
			//cout << endl;
		}
	}
	cout << ans + dp[0][m - 1][k] + dp[1][m - 1][k] << endl;
}
