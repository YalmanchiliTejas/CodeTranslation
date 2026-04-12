#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll MOD = 1000000007;
const int MX = 200010;
const ll i2 = (MOD + 1) / 2;

ll inv[MX], fact[MX], ifact[MX];

void init() {
	inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < MX; ++i) {
		fact[i] = fact[i-1] * i % MOD;
		ifact[i] = ifact[i-1] * inv[i] % MOD;
	}
}

ll comb(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

ll solve_mini(int N, int M, int K) {
	int num = N * M;
	ll ans = 0;
	rep(i, 1<<num) {
		if (__builtin_popcount(i) != K) continue;
		int s = 0;
		rep(j, num) {
			for (int k = j+1; k < num; ++k) {
				if (((i >> j) & 1) && ((i >> k) & 1)) {
					int a = j / M, b = j % M, c = k / M, d = k % M;
					s += abs(a - c) + abs(b - d);
				}
			}
		}
		ans += s;
		ans %= MOD;		
	}
	return ans;
}

ll solve(int N, int M, int K) {
	ll s = 0;
	for (int i = 1; i < N; ++i) {
		s = (s + (ll)(N-i) * i) % MOD;
	}
	ll t = 0;
	for (int i = 1; i < M; ++i) {
		t = (t + (ll)(M-i) * i) % MOD;
	}

	ll a = s * M % MOD * M % MOD;
	ll b = t * N % MOD * N % MOD;
	return (a + b) * comb(N * M - 2, K - 2) % MOD;
}

int main() {
	init();
	int N, M, K; cin >> N >> M >> K;

	ll ans = solve(N, M, K);
	if (N * M <= 20) {
		assert(ans == solve_mini(N, M, K));
	}
	cout << ans << endl;
	return 0;
}
