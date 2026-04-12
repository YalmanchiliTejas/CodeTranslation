#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <queue>
#include <deque>
#include <math.h>
#include <cmath>
#include <stack>
#include <algorithm>
#include <list>
#include <array>
#include <valarray>
#include <unordered_map>
#include <cassert>
#include <random>
#include <cstring>
#include <sstream>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pii;

#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)

ld EPS = (ld)1e-9L;
const double PI = 3.141592653589793238462;
const int INF = 1e9 + 7;
const li LINF = 4e18 + 7;


int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	
	if (k == 0) {
		cout << n * 1ll * n << endl;
		return 0;
	}

	li ans = 0;
	for (int a = k; a < n; ++a) {
		ans += n - a;
	}

	for (int b = k + 1; b + k <= n; ++b) {
		int cnt = (n - b) / b;
		ans += cnt * 1ll * (b - k);
		ans += max(n - (b + k + cnt * b) + 1, 0);
	}

	cout << ans << endl;
}