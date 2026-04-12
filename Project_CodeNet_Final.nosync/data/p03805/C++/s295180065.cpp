#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll to;
	ll d;
};


///////////////////////////





int main() {

	ll N,M;
	cin >> N>>M;

	vector<vector<ll>> g(N+1,vector<ll>(N+1,0));

	repn(i, M) {
		ll a, b;
		cin >> a >> b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	vector<ll> v(N + 1);
	repn(i, N) { v[i] = i; }

	ll ans = 0;

	do {
		ll t = 1;
		if (v[1] != 1) { t = 0; }
		repn(i, N - 1) { if (g[v[i]][v[i + 1]] == 0) { t = 0; } }
		ans += t;
	} while (next_permutation(++v.begin(), v.end()));

	cout << ans;


	system("PAUSE");
}
