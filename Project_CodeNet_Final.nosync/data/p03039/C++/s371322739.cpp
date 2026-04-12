
// E - Cell Distance

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

// mod p （pは素数）の下でのべき乗を求める
ll mod_pow(ll a, ll n, ll p) {
		ll result = 1;
		while (n > 0) {
			if (n & 1) result = result * a % p;
			a = a * a % p;
			n >>= 1;
		}
		return result;
	};

// mod p（pは素数）の下での逆元を求める（フェルマーの小定理を利用）
ll mod_inverse(ll a, ll p) {
	return mod_pow(a, p-2, p);
}

// mod p （pは素数）の下での除算 (a / b)
ll mod_devide(ll a, ll b, ll p) {
	return a * mod_inverse(b, p) % p;
}

// mod p （pは素数）の下での組み合わせ（nCk）を計算
ll mod_comb(ll n, ll k, ll p) {
	ll numerator = 1;
	for (int i=n; i>n-k; i--) {
		numerator *= i;
		numerator %= p;
	}

	ll denominator = 1;
	for (int i=k; i>0; i--) {
		denominator *= i;
		denominator %= p;
	}

	return mod_devide(numerator, denominator, p);
}

int main() {
	ll N, M, K;
	cin >> N >> M >> K;

	ll comb = mod_comb(N * M - 2, K - 2, MOD);

	// x方向
	ll x_total_dist = 0;
	for (ll dx=1; dx<=M-1; dx++) {
		// dx_total_dist = (M - dx) * (N * N) * dx;
		ll dx_total_dist =(((((M - dx) * N * N)) % MOD) * dx) % MOD;
		x_total_dist = (x_total_dist + dx_total_dist) % MOD;
	}
	//cout << "x_total_dist:" << x_total_dist << endl; // **** debug ****

	// y方向
	ll y_total_dist = 0;
	for (ll dy=1; dy<=N-1; dy++) {
		// dy_total_dist = (N - dy) * (M * M) * dy;
		ll dy_total_dist = (((((N - dy) * M * M)) % MOD) * dy) % MOD;
		y_total_dist = (y_total_dist + dy_total_dist) % MOD;
	}
	//cout << "y_total_dist:" << y_total_dist << endl; // **** debug ****

	ll ans = ((x_total_dist + y_total_dist) * comb) % MOD;

	cout << ans << endl;

	return 0;
}