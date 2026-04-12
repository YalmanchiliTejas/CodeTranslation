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
#include <random>

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
#define sq5(x) ((x) * (x) * (x) * (x) * (x))
#define N 100005

int used[N];

int main(void) {
	ll n, x, m;
	scanf("%lld%lld%lld", &n, &x, &m);
	if (x == 0) {
		printf("0\n");
		return 0;
	}

	CL(used, -1);
	used[x] = 0;

	vector<ll> v;
	ll c;

	ll X = x;
	while (true) {
		int nxt = used[x] + 1;
		x = (x * x) % m;
		if (used[x] != -1) {
			c = x;
			break;
		}

		v.pb(x);
		used[x] = nxt;
	}

	ll sum = 0;
	vector<ll> st;
	REP(i, used[c]) {
		sum += X;
		X = (X * X) % m;

		st.push_back(sum);
	}

	sum = 0;
	vector<ll> cycle;
	x = X;
	do {
		sum += x;
		x = (x * x) % m;
		cycle.pb(sum);
	} while (x != X);

	if (n <= sz(st)) {
		printf("%lld\n", st[n - 1]);
	}
	else {
		n -= sz(st);
		n--;
		ll cnt = n / sz(cycle);
		ll ans = sz(st) ? st.back() : 0; 
		ans += cnt * cycle.back();
		n %= sz(cycle);
		ans += cycle[n];

		printf("%lld\n", ans);
	}
}