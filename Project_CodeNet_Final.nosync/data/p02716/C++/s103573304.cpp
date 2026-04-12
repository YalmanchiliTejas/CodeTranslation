#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll N;
	cin >> N;
	vector<ll> A(N+2, 0);
	vector<ll> cAo(N+2, 0); // 1からの累積和
	vector<ll> cAe(N+2, 0); // 2からの累積和

	// 累積の計算
	ll ao = 0;
	ll ae = 0;
	ll cmin = 0;
	A.at(0) = 0;
	cAo.at(0) = 0;
	cAe.at(0) = 0;
	for (ll i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		A.at(i) = a;
		if (i % 2 == 1) {
			ao += a;
		}
		else {
			ae += a;
		}
		cAo.at(i) = ao;
		cAe.at(i) = ae;
		if (a < 0) {
			cmin += a;
		}
	}
	A.at(N + 1) = 0;
	cAo.at(N + 1) = ao;
	cAe.at(N + 1) = ae;

	ll cmax = cmin;
	// 累積和の計算
	if (N % 2 == 0) {
		// N is even
		for (ll i = 1; i <= N + 1; i = i + 2) {
			ll c = cAo.at(i-1) + cAe.at(N) - cAe.at(i);
			if (cmax < c) { cmax = c; }
		}
		cout << cmax << endl;
	}
	else { 
		// n is odd
		vector<ll> cAimax(N + 2, 0);
		cAimax.at(0) = cAo.at(0) - cAe.at(1);
		for (ll i = 1; i <= N+1; i++) {
			cAimax.at(i) = max(cAimax.at(i-1), cAo.at(i - 1) - cAe.at(i));
		}
		vector<ll> cAkmax(N + 2, 0);
		cAkmax.at(N + 1) = cAe.at(N) - cAo.at(N + 1);
		for (ll k = N; k >= 1; k--) {
			cAkmax.at(k) = max(cAkmax.at(k+1), cAe.at(k - 1) - cAo.at(k));
		}
		// 加算
		for (ll i = 1; i <= N; i++) {
			ll c = cAimax.at(i) + cAkmax.at(i+1) + cAo.at(N);
			if (cmax < c) { cmax = c; }
		}
		cout << cmax << endl;
	}
}
