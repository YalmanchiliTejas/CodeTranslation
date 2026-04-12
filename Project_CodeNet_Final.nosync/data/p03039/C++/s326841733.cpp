//nmCk × ある2マスに駒が置かれる確率 × 全2マス間のマンハッタン距離の総和(むずい)
#include <iostream>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int powmod(int a, int n, int mod) {
	if (n == 0) return 1;
	if (n % 2) return (a * powmod(a, n - 1, mod)) % mod;
	return powmod((a * a) % mod, n / 2, mod);
}

int mod = 1000000007;
int fact[200001];
int factInv[200001];

void init() {
	int i;
	fact[0] = 1; factInv[0] = 1;
	for (int i = 1; i < 200001; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
		factInv[i] = powmod(fact[i], mod - 2, mod);
	}
}

int comb(int n, int k) {
	if (n < k) return 0;
	return fact[n] * factInv[n - k] % mod * factInv[k] % mod;
}

int beet(int n) {
	return n * (n + 1) / 2;
}

int h, w, k;

signed main() {
	int y, x;
	
	init();
	cin >> h >> w >> k;
	int hoge = comb(h * w - 2, k - 2);
	
	int wa = 0;
	rep(y, h) {
		rep(x, w) {
			int wax = beet(x) + beet(w - 1 - x);
			int way = beet(y) + beet(h - 1 - y);
			wax %= mod;
			way %= mod;
			wa += wax * h + way * w;
			wa %= mod;
		}
	}
	wa *= powmod(2, mod - 2, mod);
	wa %= mod;
	
	cout << wa * hoge % mod << endl;
	return 0;
}