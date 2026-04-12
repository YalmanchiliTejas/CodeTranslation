#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

const int ms = 1010;

modBase<> fat[ms], ifat[ms], inv[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		inv[i] = fexp(modBase<>(i), MOD - 2);
		fat[i] = fat[i-1] * i;
		ifat[i] = ifat[i-1] * inv[i];
		assert((fat[i] * ifat[i]).val == 1);
	}
	int n, a, b, c, d;
	std::cin >> n >> a >> b >> c >> d;
	std::vector<modBase<>> ans(n+1, 0);
	ans[0] = fat[n];
	for(int i = a; i <= b; i++) {
		std::vector<modBase<>> nxt = ans;
		for(int j = c; j <= d && i * j <= n; j++) {
			modBase<> ways = fexp(ifat[i], j) * ifat[j];
			for(int k = 0; k + j*i <= n; k++) {
				nxt[k+j*i] = nxt[k+j*i] + ways * ans[k];
			}
		}
		nxt.swap(ans);
	}
	std::cout << ans.back().val << '\n';
}