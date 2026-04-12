#include <iostream>
#include <vector>
using namespace std;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T> T mod_pow(T n, T r, T m) {
	T ret = 1;
	T tmp = n;
	while (r != 0) {
		if (r % 2) {
			ret *= tmp;
		}
		tmp *= tmp;
		tmp %= m;
		ret %= m;
		r /= 2;
	}
	return ret;
}

template <typename T> T mod_inv (T a, T m) {
	return mod_pow(a, m - 2, m);
}

 template <typename T> T mod_div (T a, T b, T m) {
	return a * mod_inv(b, m) % m;
}

int main() {
	ull mod = 998244353;
	
	uint N;
	cin >> N;
	
	ull a_comb = 1;
	ull bc_comb = 1;
	ull major = 1;
	
	for(uint i=1; i<N/2; i++) {
		a_comb = mod_div(a_comb * (N - i + 1) % mod, (ull)i, mod);
		//a_comb = a_comb * (N - i + 1) / i;
		//cout << N << "C" << i << ":" << a_comb << endl;
		bc_comb = bc_comb * 2 % mod;
		ull comb = a_comb * bc_comb % mod;
		major = (major + comb) % mod;
	}
	
	major = major * 2 % mod;
	ull whole = mod_pow((ull)3, (ull)N, mod);
	
	ull ans = (whole > major) ? (whole - major) % mod : mod + whole - major;
	
	cout << ans << endl;
}
