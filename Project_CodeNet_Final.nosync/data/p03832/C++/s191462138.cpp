// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = 1e9 + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 1e3 + 5;

int FAC[N], INV[N], DP[N][N];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}
int C(int n, int k) { return (k > n ? 0 : 1LL * INV[k] * INV[n - k] % MOD * FAC[n] % MOD); }

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	FAC[0] = 1;
	for (int i = 1; i < N; i++) FAC[i] = 1LL * FAC[i - 1] * i % MOD;
	INV[N - 1] = Power(FAC[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) INV[i] = 1LL * INV[i + 1] * (i + 1) % MOD;

	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	for (int i = 0; i < N; i++) DP[0][i] = 1;
	for (int i = a; i <= n; i++) for (int j = a; j <= b; j++) {
		DP[i][j] = DP[i][j - 1];
		for (int k = 1, p = 1; k <= d && i >= j * k; k++) {
			p = 1LL * p * C(i - (k - 1) * j, j) % MOD;
			if (k >= c) DP[i][j] = (DP[i][j] + 1LL * DP[i - j * k][j - 1] * p % MOD * INV[k] % MOD) % MOD;
		}
	}
	cout << DP[n][b] << endl;


	return 0;
}
