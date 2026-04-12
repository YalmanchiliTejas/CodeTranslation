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
#define N 3005

int a[N];

ll sum[N];

int main(void) {
	int n, s;
	scanf("%d%d", &n, &s);
	REP(i, n) {
		scanf("%d", &a[i]);
	}

	CL(sum, 0);
	sum[0] = 1;

	ll mod = 998244353;
	ll total = 0;

	REP(i, n) {
		REPD(j, s) {
			if (sum[j]) {
				if (j + a[i] < s) {
					if (!j) {
						sum[j + a[i]] = (sum[j + a[i]] + (i + 1)) % mod;
					}
					else {
						sum[j + a[i]] = (sum[j + a[i]] + sum[j]) % mod;
					}
				}
				else
					if (j + a[i] == s) {
						if (!j) {
							total = (total + (i + 1) * (n - i)) % mod;
						}
						else {
							total = (total + sum[j] * (n - i)) % mod;
						}
					}
			}
		}
	}

	printf("%lld\n", total);
	//scanf("%d\n", &n);

	return 0;
}