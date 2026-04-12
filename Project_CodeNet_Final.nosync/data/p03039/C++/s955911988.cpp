#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep2(i, s, n) for (int i = s; i < (int)n; i++)
#define all(obj) obj.begin(), obj.end()
#define debug(x) cerr << #x << ":" << x << "\n"
#define vdebug(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

static int MOD;

// factorial(mod) n!
ll fact(ll n) {
	ll res = 1;
	while (n > 1) {
		res = res * n % MOD;
		n--;
	}
	return res;
}

// power(mod) x^n
ll modpow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

// inverse(mod) x^(-1)
ll inv(ll x) {
	return modpow(x, MOD - 2);
}

// permutation(mod) nPr
ll permu(ll n, ll r) {
	if (r < 0 || n < r) return 0;
	else {
		ll res = fact(n);
		res = res * inv(fact(n - r)) % MOD;
		return res;
	}
}

// combination(mod) nCr
ll combi(ll n, ll r) {
	ll res = permu(n, r);
	res = res * inv(fact(r)) % MOD;
	return res;	
}

ll modmul(ll x, ll y) {
	return x * y % MOD;
}

int main () {
	MOD = 1000000007;
	int N, M, K; cin >> N >> M >> K;
	ll x = (N - 1);
	x = modmul(x, N);
	x = modmul(x, N + 1);
	x = modmul(x, inv(6));
	x = modmul(x, M);
	x = modmul(x, M);
	ll y = (M - 1);
	y = modmul(y, M);
	y = modmul(y, M + 1);
	y = modmul(y, inv(6));
	y = modmul(y, N);
	y = modmul(y, N);
	ll z = combi(M * N - 2, K - 2);
	ll ans = (x + y) * z % MOD;
	// debug(x); debug(y); debug(z);
	cout << ans << endl;
}