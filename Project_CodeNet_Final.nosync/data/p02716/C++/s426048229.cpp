#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <iostream>
#include <functional>
#include <complex>
#include <stdlib.h>
#include <random>
#pragma comment(linker, "/STACK:836777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define FORD(i,a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-9
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(x) ((x) * (x))
#define	N 200005

ll a[N];

int main(void) {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%lld", &a[i]);
	}
	if (n % 2 == 0) {
		ll dp[2];
		ll pd[2];
		dp[1] = a[n - 1];
		dp[0] = max(a[n - 2], a[n - 1]);
		for (int i = n - 3; i >= 0; i -= 2) {
			pd[1] = dp[1] + a[i];
			pd[0] = max(pd[1], dp[0] + a[i - 1]);
			dp[0] = pd[0];
			dp[1] = pd[1];
		}

		printf("%lld\n", max(dp[0], dp[1]));
	}
	else {
		ll dp[3];
		ll pd[3];
		dp[2] = a[n - 1];
		dp[1] = max(a[n - 2], a[n - 1]);
		dp[0] = max(a[n - 3], dp[1]);

		for (int i = n - 3; i >= 0; i -= 2) {
			pd[2] = dp[2] + a[i];
			pd[1] = max(pd[2], dp[1] + a[i - 1]);
			pd[0] = max(pd[1], dp[0] + a[i - 2]);
			dp[0] = pd[0];
			dp[1] = pd[1];
			dp[2] = pd[2];
		}

		printf("%lld\n", max(dp[0], max(dp[1], dp[2])));
	}


	return 0;
}
