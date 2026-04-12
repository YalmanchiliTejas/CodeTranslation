/**
 * @jakestrj
 */

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include "bits/stdc++.h"
using namespace std;
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define rep(i, j, k) for(int i=(j);i<(k);++i)
#define repi(i, j, k) for(int i=(j);i<=(k);++i)
#define per(i, j, k) for(int i=(j);i>(k);--i)
#define peri(i, j, k) for(int i=(j);i>=(k);--i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end(), greater<int>()
#define mem(a, b) memset(a, (b), sizeof(a))
#define mem2(a, b) memset(a, (b), sizeof(a[0][0])*len(a)*len(a[0]))
#define sz(x) ((int)(x).size())
#define len(x) (int)(sizeof(x)/sizeof(x[0]))
#define endl "\n"
#define INF 1e18
#define EPS 1e-9
#define PI 2*acos(0)
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
typedef tuple<int, int, int> trio;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<int,int> mpii;
typedef set<int> si;

#define pli pair<ll, int>
struct C {
	void solve(std::istream& cin, std::ostream& cout) {
		int n; cin >> n;
		vector<pli > uns, X;
		repi(i, 1, n){
			 ll x; cin >> x;
			 X.eb(x, i); uns.eb(x, i);
		}
		sort(all(X), [&](pli a, pli b){
			return a.f < b.first;
		});
		int res[n+1];
		rep(i, 0, n){
			ll val = X[i].f; int idx = X[i].s;
			int l = ((n)>>1);
			res[idx] = X[l - (i>=l?1:0)].first;
		}
		repi(i, 1, n) cout << res[i] << endl;
	}
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	C solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
