#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.14159265358979;
static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

static const int bn = 32;

ll n, m;
ll c[9][9] = {};
bool v[9] = {};

ll total = 0;
bool allvisited() {
	repe(i, 1, n) {
		if (!v[i]) {
			return false;
		}
	}
	return true;
}
void dfs(int k) {
	if (allvisited()) {
		total++;
		return;
	}

	repe(i, 1, n) {
		if (k != i && c[k][i] && !v[i]) {
			v[i] = true;
			dfs(i);
			v[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	rep(i, 0, m) {
		ll a, b; cin >> a >> b;
		c[a][b] = 1;
		c[b][a] = 1;
	}

	v[1] = true;
	dfs(1);

	cout << total << endl;
	return 0;
}