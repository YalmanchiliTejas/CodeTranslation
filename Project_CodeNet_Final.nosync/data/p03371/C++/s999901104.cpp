#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <queue>
#include <functional>
#include <cassert>
#include <cmath>
#include <set>

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define NL << endl

using namespace std;
using ll = long long;
using ull = unsigned long long;


int main() {

	int a, b, c, x, y;

	cin >> a >> b >> c >> x >> y;

	int ans = 1e9;

	for(int i = 0; i <= max(x, y); i++) {
		int p = i *c * 2;
		if (x > i) p += (x - i) * a;
		if (y > i) p += (y - i) * b;

		ans = min(ans, p);
	}
	
	cout << ans NL;

	return 0;

}