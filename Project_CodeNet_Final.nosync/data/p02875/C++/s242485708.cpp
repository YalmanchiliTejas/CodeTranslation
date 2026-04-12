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
const int INF = 1e9;
const ll MOD = 998244353;
 
////////////////////////////////////////////////////////////////////
 
const int N = 1e7 + 5;

int F[N], I[N];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}
int C(int n, int r) { 
	if (n < 0 || n < r) return 0;
	return 1LL * I[r] * I[n - r] % MOD * F[n] % MOD;
}

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	F[0] = 1;
	for (int i = 1; i < N; i++) F[i] = 1LL * i * F[i - 1] % MOD;
	I[N - 1] = Power(F[N - 1], MOD - 2);
	for (int i = N - 1; i > 0; i--) I[i - 1] = 1LL * i * I[i] % MOD;

	int n; cin >> n;
	int ans = Power(3, n);
	for (int i = n / 2 + 1; i <= n; i++) ans = (ans - 2LL * C(n, i) * Power(2, n - i) % MOD + MOD) % MOD;
	cout << ans << endl;	

	return 0;
}
