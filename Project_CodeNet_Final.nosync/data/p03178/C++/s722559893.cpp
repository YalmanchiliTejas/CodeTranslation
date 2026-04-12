// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e4 + 5, D = 1e2 + 5;

int DP[N][D];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	
	string k; cin >> k;
	int n = sz(k), d, ans = 0, sum = 0; cin >> d;
	DP[0][0] = 1;
	for (int i = 1; i < n; i++) for (int j = 0; j < d; j++) 
		for (int l = 0; l < 10; l++) DP[i][j] = (DP[i][j] + DP[i - 1][(j - l % d + d) % d]) % MOD;
	for (int i = 0; i < n; i++) for (int j = 0; j < k[i] - '0'; j++, sum = (sum + 1) % d) ans = (ans + DP[n - i - 1][(d - sum) % d]) % MOD;
	ans = (ans - (sum % d != 0) + MOD) % MOD;
	cout << ans << endl;

	return 0;
}
