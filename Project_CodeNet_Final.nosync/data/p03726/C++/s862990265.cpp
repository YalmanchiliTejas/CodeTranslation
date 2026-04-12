#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;

const int N = 1e5 + 123;
int n, a[N];
vi adj[N];

void dfs(int v, int p) {
	int child = 0;
	for (int to : adj[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v);
		if (adj[to].size() == 1) {
			a[to] = 1;
		}
		child += a[to];
	}
	if (child >= 2) {
		cout << "First";
		exit(0);
	}
	if (child == 1) {
		a[v] = 0;
	}	else {
		a[v] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1, 1);
	if (a[1] == 1) {
		cout << "First";
	}	else {
		cout << "Second";
	}
}
