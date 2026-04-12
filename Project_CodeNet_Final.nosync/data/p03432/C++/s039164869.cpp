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

struct NumberTheoreticTransform {
    int mod;
    int root;

    NumberTheoreticTransform(int mod, int root) : mod(mod), root(root) {}

    int mul(int x, int y) {
        return int64_t(x) * y % mod;
    }

    int add(int x, int y) {
        return (x += y) >= mod ? x - mod : x;
    }

    int pow(int x, int y) {
        int res = 1;
        while (y > 0) {
            if (y & 1) res = mul(res, x);
            x = mul(x, x);
            y >>= 1;
        }
        return res;
    }

    int inv(int x) {
        return pow(x, mod - 2);
    }

    void ntt(std::vector<int> &a, bool rev = false) {
        int n = a.size();
        int h = 0;
        for (int i = 0; 1 << i < n; i++) h++;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (int k = 0; k < h; k++) {
            	j |= (i >> k & 1) << (h - 1 - k);
            }
            if (i < j) std::swap(a[i], a[j]);
        }
        for (int i = 1; i < n; i *= 2) {
            int w = pow(root, (mod - 1) / (i * 2));
            if (rev) w = inv(w);
            for (int j = 0; j < n; j += i * 2) {
                int wn = 1;
                for (int k = 0; k < i; k++) {
                    int s = a[j + k + 0];
                    int t = mul(a[j + k + i], wn);
                    a[j + k + 0] = add(s, t);
                    a[j + k + i] = add(s, mod - t);
                    wn = mul(wn, w);
                }
            }
        }
        int v = inv(n);
        if (rev) for (int i = 0; i < n; i++) a[i] = mul(a[i], v);
    }

    std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
        int s = a.size() + b.size() - 1;
        int t = 1;
        while (t < s) t *= 2;
        a.resize(t);
        b.resize(t);
        ntt(a);
        ntt(b);
        for (int i = 0; i < t; i++) {
            a[i] = mul(a[i], b[i]);
        }
        ntt(a, true);

        a.resize(s);
        return a;
    }
};

const ll MOD = 998244353;
const int MN = 8010;
const int MM = 310;

ll mod_pow(ll x, ll n) {
	ll res = 1;
	for (; n; n /= 2, x = x * x % MOD) {
		if (n & 1) {
			res = res * x % MOD;
		}
	}
	return res;
}

int N, M;
ll dp[MM][MN];
ll fact[MN], ifact[MN], inv[MN];

int main() {
	inv[1] = 1;
    for (int i = 2; i < MN; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }

    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        ifact[i] = ifact[i-1] * inv[i] % MOD;
    }

	cin >> N >> M;

	NumberTheoreticTransform ntt(998244353, 3);

	dp[0][0] = 1;

	for (int i = 1; i <= M; ++i) {
		vi v1(N + 1), v2(N + 1);

		for (int j = 0; j <= N; ++j) {
			v1[j] = dp[i-1][j] * ifact[j] % MOD;
			v2[j] = ifact[j+2];
		}

		v1 = ntt.mul(v1, v2);

		for (int j = 0; j <= N; ++j) {
			ll t = v1[j] * fact[j+2] % MOD;
			t = (t - (j + 1) * (j + 2) / 2 * dp[i-1][j]) % MOD;
			if (t < 0) t += MOD;
			t = (t + dp[i-1][j] * (j * (j + 1) / 2 + 1)) % MOD;
			dp[i][j] = t;
		}
	}

	ll ans = 0;
	for (int i = 0; i <= N; ++i) {
		ans = (ans + dp[M][i] * fact[N] % MOD * ifact[i] % MOD * ifact[N-i]) % MOD;
	}

	cout << ans << endl;

	return 0;
}