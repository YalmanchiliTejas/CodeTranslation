#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int INF = INT_MAX / 2;
const long double PI = 3.141592653289793;
using namespace std;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
#define lld long double
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> vp;
typedef vector<tuple<ll, ll, ll>> vt;
//vector<vector<ll>> vv(n, vector<ll>(n));

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	x -= (y + 2 * z);
	if (x < 0) cout << 0 << endl;
	else cout << x / (y + z) + 1 << endl;
}