//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = int64_t;
using ull = uint64_t;
 
template <typename T> vector<T> make_vec_nd(T init, size_t size) {
  return vector<T>(size, init);
}
template <typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
  auto inner = make_vec_nd(init, rest...);
  return vector<decltype(inner)>(size, inner);
}
 
struct Mod {
	static ll BASE;
	ll value = 0;
	static ll residue(ll value) { return (value % BASE + BASE) % BASE; }
	Mod(ll value)
	: value(residue(value)) {}
	Mod operator+(const Mod& rhs) const { return Mod(value + rhs.value); }
	void operator+=(const Mod& rhs) { *this = *this + rhs; }
	Mod operator-(const Mod& rhs) const { return Mod(value - rhs.value); }
	void operator-=(const Mod& rhs) { *this = *this - rhs; }
	Mod operator*(const Mod& rhs) const { return Mod(value * rhs.value); }
	void operator*=(const Mod& rhs) { *this = *this * rhs; }
};
ll Mod::BASE = 1000000007;
 
int main() {
	string K;
	cin >> K;
	vector<ll> Ki;
	for (ll i = 0; i < K.size(); i++) {
		Ki.push_back(K[i] - '0');
	}
	ll D;
	cin >> D;
	auto dig_sum = make_vec_nd((ll)0, K.size() + 1);
	for (ll i = 1; i <= K.size(); i++) {
		dig_sum[i] = (dig_sum[i-1] + Ki[i-1]) % D;
	}
	auto dp = make_vec_nd((Mod)0, K.size() + 1, D);
	for (ll i = 1; i <= K.size(); i++) {
		for (ll d = 0; d < D; d++) {
			for (ll n = 0; n < 10; n++) {
				if ((dig_sum[i-1] + n) % D == d && n < Ki[i-1]) {
					dp[i][d] += 1;
				}
				dp[i][d] += dp[i-1][((d - n) % D + D) % D];
			}
		}
	}
	Mod ans = dp[K.size()][0];
	if (dig_sum[K.size()] == 0) {
		ans += 1;
	}
	ans -= 1;
	cout << ans.value << endl;
}
