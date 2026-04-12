#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int exp_mod(long long a, long long b, int m) {
	long long res = 1;
	while (b > 0) {
		if (b&1)
			res = (res * a)%m;
		a = (a * a)%m;
		b >>= 1;
	}
	return (int)res;
}

int fact_mod(int n, int m) {
	long long res = 1;
	for (int i=n; i>0; --i)
		res = (res * i)%m;
	return (int)res;
}

int comb_mod(int n, int r) {
	long long res = 1;
	for (int i=0; i<r; ++i)
		res = (res * (n - i) )%MOD;
	return ( res * exp_mod(fact_mod(r, MOD), MOD-2, MOD) ) % MOD;
}

int main() {
  // 入力
  ll N, M, K;
  cin >> N >> M >> K;

  ll R = comb_mod(N * M - 2, K - 2);

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
        ll u = (N - i + 1);
        ll d = i;
        ll l = j;
        ll r = (M - j + 1);
        ll D = 0;
        D += u * l * (u + l - 2) / 2;
        D += u * r * (u + r - 2) / 2;
        D += d * l * (d + l - 2) / 2;
        D += d * r * (d + r - 2) / 2;
        D -= u * (u - 1) / 2;
        D -= d * (d - 1) / 2;
        D -= l * (l - 1) / 2;
        D -= r * (r - 1) / 2;
        ans = (ans + D) % MOD;
    }
  }
  ans = (ans * exp_mod(2, MOD-2, MOD)) % MOD;
  ans = (ans * R) % MOD;
  cout << ans << endl;
  return 0;
}
