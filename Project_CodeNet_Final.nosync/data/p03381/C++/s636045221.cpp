#pragma comment(linker, "/STACK:640000000")
#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int maxn = (int)2e5 + 10;

int a[maxn];

int main() {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	vector<pii> v;

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		v.pb(mp(x, i));
	}

	sort(all(v));

	int m = n / 2 - 1;

	for (int i = 0; i < n; i++) {
		if (i <= m) {
			a[v[i].second] = v[m + 1].first;
		} else {
			a[v[i].second] = v[m].first;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}