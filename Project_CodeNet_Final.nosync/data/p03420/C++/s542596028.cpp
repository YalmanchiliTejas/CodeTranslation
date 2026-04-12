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

int main() {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	int n, k; cin >> n >> k;

	ll res = 0;

	for (int b = k + 1; b <= n; b++) {
		res += n / b * 1LL * (b - k);
		res += max(n % b - k + 1, 0);
	}

	if (k == 0) res -= n - k;

	cout << res << endl;

	return 0;
}