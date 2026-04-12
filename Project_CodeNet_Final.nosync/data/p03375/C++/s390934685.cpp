#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;

// 1～nのmod逆元を計算する(modは素数), O(n)
void ModInv(int n, vector<ll> &inv, int mod) {
	inv[0] = 0;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
	}
}

// 0!～n!のmod逆元を計算する(modは素数), O(n)
void FacInv(int n, vector<ll> inv, vector<ll> &fac, vector<ll> &facInv, int mod) {
	fac[0] = facInv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		facInv[i] = (facInv[i - 1] * inv[i]) % mod;
	}
}

// nCkをmodで割った余りを求める。mod素数限定
// ModInv()とFacInv()が必要
long CombiMod(int n, int k, int mod, const vll &inv, const vll &fac, const vll &facInv) {
	if (n == 0 && k == 0) return 1;
	if (n <= 0 || k < 0 || k > n) return 0;
	if (k == 0) return 1;

	return (((fac[n] * facInv[k]) % mod) * facInv[n - k]) % mod;
}

// 繰り返し二乗法で (x^n)%mod を計算する O(log n)
ll powMod(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;

	// 階乗逆元の事前計算
	vector<ll> inv(N + 1);
	vector<ll> fac(N + 1);
	vector<ll> facInv(N + 1);
	ModInv(N, inv, M);
	FacInv(N, inv, fac, facInv, M);

	vll ways(N + 1, 0);
	vvll ways2(N + 1, vll(N + 1, 0));
	
	// ways2 の事前計算
	ways2[0][0] = 1;
	repr(i, 1, N + 1) {
		rep(j, N + 1) {
			if (j > i) {
				ways2[i][j] = 0;
			}
			else if (j == 0 || j == i) {
				ways2[i][j] = 1;
			}
			else {
				ways2[i][j] = (((j + 1) * ways2[i - 1][j]) % M + ways2[i - 1][j - 1]) % M;
			}
		}
	}

	/*
	// ways2 のデバッグ用出力
	rep(i, N + 1) {
		rep(j, N + 1) {
			cerr << ways2[i][j] << " ";
		}
		cerr << endl;
	}
	*/

	// ways の事前計算
	rep(i, N + 1) {
		rep(j, i + 1) {
			// ways2(i,j)*2^((N-i)j) を足す
			ways[i] += ways2[i][j] * powMod(2, (ll)(N - i) * j, M);
			ways[i] %= M;
		}
		// 2^(2^(N-i)) を掛ける
		ways[i] *= powMod(2, powMod(2, N - i, M - 1), M);
		ways[i] %= M;
	}

	// 余事象と包除原理に基づいて答えを計算
	ll ans = 0;
	rep(i, N + 1) {
		// 今回足し引きする値（Σの中身）
		ll val = (CombiMod(N, i, M, inv, fac, facInv) * ways[i]) % M;

		// i の偶奇で足し引きを切り替える
		if (i % 2 == 0) {
			ans = (ans + val) % M;
		}
		else {
			ans = (ans - val + M) % M;
		}
	}

	cout << ans << endl;

	return 0;
}