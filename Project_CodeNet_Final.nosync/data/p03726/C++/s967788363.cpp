#include <bits/stdc++.h>

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pii pair<int, int>
#define mp make_pair
#define f first
#define ll long long
#define ld long double
#define s second
#define vec vector<int>

using namespace std;

const int N = (int) 1e5 + 100;
const int M = (int) 1e5 + 100;
const int K = (int) 200;
const int INF = (int) 1e9 + 7;
const int mod = (int) 998244353;
const ld EPS = (ld) 1e-9;
const ll LINF = (ll) 1e18;

int n;
int a[N], b[N];
bool was[N];
vec v[N];

void dfs(int x, int p = -1) {
	vec c;
	for (auto it : v[x]) {
		if (it == p)
			continue;
		dfs(it, x);
		if (!was[it]) {
			c.pb(it);
		}
	}
	if (sz(c) > 1) {
		cout << "First";
		exit(0);
	}
	if (sz(c) == 1) {
		was[x] = 1;
		was[c[0]] = 1;
	}
}

int main() {
	#ifdef sony
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	srand(time(0));
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> b[i];
		v[a[i]].pb(b[i]);
		v[b[i]].pb(a[i]);
	}
	dfs(1);
	cout << (was[1] ? "Second" : "First");
	return 0;		
}