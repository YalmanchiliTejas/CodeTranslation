#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

ll n;
ll a[50];

bool solve(ll k) {
	ll res = 0;
	REP(i, n) res += (a[i] + k - (n - 1) + n) / (n + 1);
	return res <= k;
}

int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> a[i];
	ll l = -1, h = (10000000000000000 + 1000) * 50 + 1;
	while (l + 1 < h) {
		ll m = (l + h) / 2;
		ll res = -1;
		for (ll i = max(l + 1, m - n); i <= m; ++i) if (solve(i)) {
			res = i;
			break;
		}
		if (res >= 0) h = res;
		else l = m;
	}
	cout << h << endl;
	return 0;
}
