#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

constexpr int MOD = 1e9 + 7;
i64 mod_pow(i64 x, i64 n = MOD - 2) {
	i64 ret = 1;
	while(n) {
		if(n & 1) (ret *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return ret;
}

std::vector<i64> fact, inv;
i64 comb(int n, int r) {
	return fact[n] * inv[n - r] % MOD * inv[r] % MOD;
}

int main() {
	i64 h, w, k; scanf("%lld%lld%lld", &h, &w, &k);
	fact.resize(h * w + 1, 1); inv.resize(fact.size(), 1);
	for(i64 i = 0; i < (int)fact.size() - 1; i++) fact[i + 1] = (i + 1) * fact[i] % MOD;
	for(int i = 0; i < fact.size(); i++) inv[i] = mod_pow(fact[i]);
	
	i64 ans = 0;
	const i64 latte = comb(h * w - 2, k - 2);
	for(int loop = 0; loop < 2; loop++) {
		for(i64 d = 1; d < h; d++) {
			i64 A = h - d;
			ans += d * w % MOD * w % MOD * A % MOD;
			ans %= MOD;
		}
		std::swap(h, w);
	}
	(ans *= latte) %= MOD;
	
	printf("%lld\n", ans);
	return 0;
}
