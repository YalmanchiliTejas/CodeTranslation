#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <istream>
#include <ostream>

#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,n) for(ll i=0; i < (n); ++i)
#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)

#define OPLT(T) bool operator<(const T & lop_, const T & rop_)
#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

int uf[100100];
void init() {
	rep(i,100100) uf[i] = i;
}
int find(int a) {
	if(uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
int same(int a, int b) {
	return find(a) == find(b);
}
bool mage(int a, int b) {
	if(find(a) == find(b)) return false;
	uf[find(a)] = find(b);
	return true;
}

int main() {
	int N; cin >> N;
	vector<pll> x(N), y(N);
	vector<pair<ll,pii> > d;
	rep(i,N) {
		cin >> x[i].fi >> y[i].fi;
		x[i].se = y[i].se = i;
	}
	sort(all(x));
	sort(all(y));
	for(int i = 1; i < N; i++) {
		d.push_back(pair<ll,pii>(abs(x[i].fi-x[i-1].fi),pii(x[i].se, x[i-1].se)));
		d.push_back(pair<ll,pii>(abs(y[i].fi-y[i-1].fi),pii(y[i].se, y[i-1].se)));
	}
	sort(all(d));
	ll res = 0;
	init();
	rep(i,d.size()) {
		if(mage(d[i].se.fi, d[i].se.se))
			res += d[i].fi;
	}
	cout << res << endl;
	return 0;
}
