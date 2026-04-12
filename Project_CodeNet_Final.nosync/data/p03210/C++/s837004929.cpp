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
#include <deque>

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



signed main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		cout << "YES" NL;
	} else {
		cout << "NO" NL;
	}

	return 0;
}