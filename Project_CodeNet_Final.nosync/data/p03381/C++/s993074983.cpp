#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x, n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;   
//typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int n;
vector<P> v;
int idx[200000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	cin >> n;
	REP(i, n) {
		int x;cin >> x;
		v.pb(P(x, i));
	}
	sort(ALL(v));
	REP(i, n) {
		idx[v[i].se] = i;
	}
	REP(i, n) {
		if(idx[i] < n/2) cout << v[n/2].fi << endl;
		else cout << v[n/2 - 1].fi << endl;
	}

    return 0;
}
