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
const ll INF = 1e9;
const ll MOD = 998244353;
 
////////////////////////////////////////////////////////////////////

const int N = 3e3 + 5;

int A[N], DP[N][N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n, s; cin >> n >> s;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		DP[i][A[i]] = i;
		for (int j = A[i]; j <= s; j++) DP[i][j] = (DP[i][j] + DP[i - 1][j - A[i]]) % MOD;
		ans = (ans + 1LL * DP[i][s] * (n - i + 1) % MOD) % MOD;
		for (int j = 1; j <= s; j++) DP[i][j] = (DP[i][j] + DP[i - 1][j]) % MOD;
	}
	cout << ans << endl;

	return 0;
}
