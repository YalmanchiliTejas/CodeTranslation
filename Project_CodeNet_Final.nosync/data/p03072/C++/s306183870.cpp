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
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;


int main() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	int maxx = 0,ans=0;
	rep(i, 0, n) {
		if (maxx <= a[i]) {
			ans++;
			maxx = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}