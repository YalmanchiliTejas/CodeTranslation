#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	const int mod = 1e9 + 7;
	string s;
	int D;
	cin >> s >> D;
	int n = sz(s);
	vector<vi> ways(n + 1, vi(D, 0));
	ways[0][0] = 1;
	for (int len = 1; len <= n; len++) {
		for (int r = 0; r < D; r++) {
			for (int d = 0; d < 10; d++) {
				int rr = (r + d) % D;
				(ways[len][rr] += ways[len - 1][r]) %= mod;
			}
		}
	}
	int ans = 0;
	int tmp = 0;
	vi num;
	for (char d : s) {
		tmp += (d - '0');
		num.pb(d - '0');
	}
	ans += (tmp % D == 0);
	int pref_rem = 0;
	for (int i = 0; i < n; i++) {
		for (int d = (i > 0 ? 0 : 1); d < num[i]; d++) {
			int want_rem = ((-(pref_rem + d)) % D + D) % D;
			(ans += ways[n - i - 1][want_rem]) %= mod;
		}
		(pref_rem += num[i]) %= D;
	}
	(ans += ways[n - 1][0]) %= mod;
	(ans += mod - 1) %= mod;
	cout << ans;
}
