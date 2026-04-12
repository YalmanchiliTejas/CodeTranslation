/*
				C++
				encoding: UTF-8
				Last Modified: 29/Aug/20 05:47:00 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

int power (int a, int b, int m) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return r;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	const int mod = 1e9 + 7;
	vector< int > arr (n);
	int sum = 0;
	for (auto& i : arr) {
		cin >> i;
		sum += i;
		sum %= mod;
	}

	int sq = (sum * sum) % mod;
	int p = 0;
	for (auto& i : arr) {
		p += i * i;
		p %= mod;
	}

	int ans = (sq - p + mod) % mod;
	int d = power (2, mod - 2, mod);

	print (ans * d % mod);

	return 0;
}