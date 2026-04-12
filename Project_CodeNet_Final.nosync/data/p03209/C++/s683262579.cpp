#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
vector<ll> sum, p;
ll rec(ll n, ll x)
{
	if (n == 0) return x <= 0 ? 0 : 1;
	else if (x <= 1 + sum[n - 1]) return rec(n - 1, x - 1);
	else return p[n - 1] + 1 + rec(n - 1, x - sum[n - 1] - 2);
}
int main()
{
	// ABC115-D, 1084, 20:46(UNSOLVED),
	ll n, x; cin >> n >> x;
	sum.resize(n); p.resize(n);
	sum[0] = p[0] = 1;
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
	cout << rec(n, x) << endl;
	return 0;
}