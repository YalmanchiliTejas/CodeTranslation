#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <iomanip>
#include <queue>
#include <functional>
#include <cassert>
#include <cmath>
#include <set>
#include <map>
#include <numeric>

#define NL << endl

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INTMAX = numeric_limits<int>::max();
const int INTMIN = numeric_limits<int>::min();
const ll LLMAX = numeric_limits<long long>::max();
const ll LLMIN = numeric_limits<long long>::min();
const int MOD = 1000000007;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

using namespace std;

int n;
vector<int> a;

ll calc(int s) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (i < s) {
			res -= a[i] * 2;
		} else {
			res += a[i] * 2;
		}
	}

	return res;
}

signed main() {
	cin >> n;
	a.resize(n);
	for (auto& e : a) cin >> e;

	sort(a.begin(), a.end());

	ll sum = 0;
	ll sum2 = 0;
	if(n & 1) {
		sum = calc((n + 1) / 2);
		sum += a[n / 2] + a[n / 2 - 1];
		sum2 = calc(n / 2);
		sum2 -= a[n / 2] + a[n / 2 + 1];
	} else {
		sum = calc(n / 2);
		sum += a[n / 2 - 1] - a[n / 2];
	}

	cout << max(sum, sum2) NL;

	return 0;

}

