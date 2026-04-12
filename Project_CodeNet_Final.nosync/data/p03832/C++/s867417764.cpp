#include<iostream>

using namespace std;

typedef long long ll;

namespace comb {
	ll fact[500001];
	ll fact_inv[500001];
	const ll MOD = 1000000007;

	ll modpow(ll a, ll b) {
		ll base = 1, kakeru = a;
		while (b > 0) {
			if (b & 1)base *= kakeru, base %= MOD;
			kakeru *= kakeru, kakeru %= MOD;
			b >>= 1;
		}
		return base;
	}

	void setup() {
		fact[0] = 1, fact[1] = 1;
		for (int i = 2; i <= 500000; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
		}

		fact_inv[500000] = modpow(fact[500000], MOD - 2);

		for (int i = 499999; i >= 0; i--) {
			fact_inv[i] = fact_inv[i + 1] * (i + 1);
			fact_inv[i] %= MOD;
		}

	}

	ll combination(int a, int b) {
		if (a - b < 0)return 0;
		ll ret = fact[a];
		ret *= fact_inv[b], ret %= MOD;
		ret *= fact_inv[a - b], ret %= MOD;
		return ret;
	}

	ll permutation(int a, int b) {
		if (a - b < 0)return 0;
		ll ret = fact[a];
		ret *= fact_inv[a - b], ret %= MOD;
		return ret;
	}

	ll homogeneous(int a, int b) {
		return combination(a + b - 1, b);
	}

}

int N, A, B, C, D;

ll dp[1000 + 10][1000 + 10];//dp[i][j] := (i > 0)ならi + A - 1人のグループを作り終えて、合計j人使った時, i == 0の時はなにも使ってないとき

int main() {
	comb::setup();
	cin >> N >> A >> B >> C >> D;

	dp[0][0] = comb::fact[N];

	for (int i = 1; i <= (B - A + 1); i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= comb::MOD;
			for (int k = C; k <= D; k++) {
				if (k * (A + i - 1) <= j) {
					dp[i][j] += (((dp[i - 1][j - k * (A + i - 1)] * comb::modpow(comb::fact_inv[A + i - 1], k)) 
						% comb::MOD) * comb::fact_inv[k]) % comb::MOD;
					dp[i][j] %= comb::MOD;
				}
				else break;
			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[B - A + 1][N] << endl;
	return 0;
}