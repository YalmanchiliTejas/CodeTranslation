#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

vector<pair<int, int>> X[1003];
ll perm[1002][1002], dp[1002][1002], jk[1002][1002];
ll fact[1002];

//mod冪乗
ll modpow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2)
			ans *= a;
		a *= a;
		a %= MOD;
		ans %= MOD;
		b /= 2;
	}
	return ans;
}

//mod割り算
ll moddiv(ll a, ll b) {
	a %= MOD;
	return (a * modpow(b, MOD - 2)) % MOD;
}

ll A, B, C, D;

int main() {
	ll N, E;
	int n;
	cin >> N >> A >> B >> C >> D;
	for (int i = 1;i <= N;i++) {
		E = 1;
		for (int j = i;j > 0;j--) {
			E *= j;
			E %= MOD;
			perm[i][i - j + 1] = E;
		}
	}

	E = 1;
	for (int i = 1;i <= N;i++) {
		E *= i;
		E %= MOD;
		fact[i] = E;
	}

	E = 1;
	for (int j = A;j <= B;j++) {
		for (int k = C;k <= D;k++) {
			E = (modpow(fact[j], k) * fact[k]) % MOD;
			jk[j][k] = E;
		}
	}

	int a, b, cnt = 0;
	dp[N][A - 1] = 1;
	for (int j = A;j <= B;j++) {
		for (int i = N;i >= 0;i--) {
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= MOD;
			if (i < j * C)continue;
			for (int k = C;k <= D;k++) {
				if (i < j * k) {
					break;
				}
				cnt++;
				dp[i - j * k][j] += dp[i][j - 1] * moddiv(perm[i][j * k], jk[j][k]);
				dp[i - j * k][j] %= MOD;
			}
		}
	}
	cout << dp[0][B] << endl;
}