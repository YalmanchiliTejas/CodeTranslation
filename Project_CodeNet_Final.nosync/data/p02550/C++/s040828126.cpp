#include <bits/stdc++.h>

#define debug_input freopen("stdin.in", "r", stdin)
#define debug_output freopen("stdout.out", "w", stdout)
#define FOR(i, a, b) for(ll i = a; i <= b; i++)
#define FORALL(i, n) for(ll i = 0; i < n; i++)
#define FORD(i, a, b) for(ll i = a; i >= b; i--)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())
#define NP(a) next_permutation(a.begin(), a.end())
#define ALL(a) a.begin, a.end()
#define mp make_pair
#define pb push_back
#define endl "\n"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll n, x, m;
vector<ll> v;
map<ll, bool> vis;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x >> m;	 

	while(not vis[x]) {
		v.pb(x);
		vis[x] = 1;
		x = (x * x) % m;
	}

	ll loopStart = 0;
	while(v[loopStart] != x) loopStart++;

	ll s = v.size();
	ll tot = 0;
	ll totLoop = 0;

	if(n <= loopStart) {
		FORALL(i, n) tot += v[i];
		cout << tot << endl;

		return 0;
	}

	FORALL(i, loopStart) tot += v[i];
	FOR(i, loopStart, s - 1) totLoop += v[i];

	n -= loopStart;
	tot += totLoop * (n / (s - loopStart));
	n %= s - loopStart;
	FORALL(i, n) tot += v[loopStart + i];

	cout << tot << endl;
	return 0;
}