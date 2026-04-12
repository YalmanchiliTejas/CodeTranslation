#include <bits/stdc++.h>

using ll = long long;

using namespace std;
template<int mod>
struct ModComb {
	using ll = long long;
	vector<ll> fact;
	vector<ll> facti;
	ModComb(int n) {
		init(n);
	}
	void init(int n) {
		fact.resize(n);
		facti.resize(n);
		fact[0] = 1;
		for (int i = 1; i < n; i++) {
			fact[i] = fact[i-1] * i % mod;
		}
		facti[n-1] = po(fact[n-1], mod - 2);
		for (int i = n-2; i >= 0; i--) {
			facti[i] = facti[i+1] * (i + 1) % mod;
		}
	}
	ll nCr(int a, int b) {
		return (fact[a] * facti[b] % mod) * facti[a-b] % mod;
	}
	ll po(ll next, int cnt) {
		ll res = 1;
		if (cnt == 0) return 1;
		if (cnt & 1) res = res * next % mod;
		return res * po(next * next % mod, cnt >> 1) % mod;
	}
};
using modcomb = ModComb<1000000007>;

ll calc(ll H, ll W, int K)
{
  if (K <= 1) return 0;
  modcomb m(H * W + 100);
  ll res = 0;
  ll HH = H * H % 1000000007;
  for (int i = 1; i < W; i++) {
    ll t = HH * i % 1000000007;
    res += m.nCr(H * W - 2, K - 2) * t % 1000000007 * (W - i);
    res %= 1000000007;
  }
  return res;
}

int main()
{
  int H, W, K;
  cin >> H >> W >> K;
  cout << (calc(H, W, K) + calc(W, H, K)) % 1000000007 << endl;
}