#define rep(i,n) for (int i = 0; i < n; i++)
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;


int main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int ans = min(a*d + b * e, max(d, e)*c * 2);
	if (d > e) ans = min(ans, 2 * c*e + (d - e)*a);
	else ans = min(ans, 2 * c*d + (e - d)*b);
	cout << ans << endl;
	return 0;
}
