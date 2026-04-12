#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll calc_size(int level) {
	return (1LL << (2 + level)) - 3LL;
}

ll calc_patty(int level) {
	return (1LL << (1 + level)) - 1LL;
}

ll solve(int level, ll x) {
	if (level == 0 && x == 1) return 1LL;
	--x;
	if (x == 0) return 0LL;
	ll sz = calc_size(level - 1);
	if (x <= sz) 
		return solve(level - 1, x);
	ll res = calc_patty(level - 1);
	x -= sz;
	if (x == 0) return res;
	res++; --x;
	if (x == 0) return res;
	res += solve(level - 1, min(sz, x));
	return res;
}

int main() {
	int N; ll X;
	cin >> N >> X;
	cout << solve(N, X) << endl;
	return 0;
}