#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i,n)	for(int i=0;i<n;i++)
#define srep(i,a,n)	for(int i=a;i<n;i++)
#define REP(i,n)	for(int i=0;i<=n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define mp(a,b)	make_pair(a,b)
#define fst	first
#define scn second

const ll inf = (ll)1e9 + 7;
const ll mod = (ll)1e9 + 7;
const ld eps = 1e-9;

class segtree {
public:
	vint big, sml;
	int N=1;
	segtree(int n,vint dat) {
		while (N < n)	N <<= 1;
		big.resize(2 * N);	sml.resize(2 * N);
		rep(i, 2 * N) {
			big[i] = 0;
			sml[i] = inf;
		}
		rep(i, n)	big[N - 1 + i] = sml[N - 1 + i] = dat[i];
		rrep(i, N - 1) {
			big[i] = max(big[2 * i + 1], big[2 * i + 2]);
			sml[i] = min(sml[2 * i + 1], sml[2 * i + 2]);
		}
	}
	int getmin(int l, int r, int a, int b, int k) {
		if (r <= a || b <= l)	return inf;
		if (a <= l&&r <= b)	return sml[k];
		return min(this->getmin(l, (l + r) / 2, a, b, 2 * k + 1), this->getmin((l + r) / 2, r, a, b, 2 * k + 2));
	}
	int getmax(int l, int r, int a, int b, int k) {
		if (r <= a || b <= l)	return 0;
		if (a <= l&&r <= b)	return big[k];
		return max(this->getmax(l, (l + r) / 2, a, b, 2 * k + 1), this->getmax((l + r) / 2, r, a, b, 2 * k + 2));
	}
};

int x[200010], y[200010];
int n;

ll solve1() {//different colored
	vint r(n,0), b(n,0);
	rep(i, n) {
		r[i]=max(x[i], y[i]);
		b[i]=min(x[i], y[i]);
	}
	sort(r.begin(), r.end());
	sort(b.begin(), b.end());
	return (ll)(r[n - 1] - r[0])*(b[n - 1] - b[0]);
}

ll solve2() {//same colored
	vector<pii> dat(n);
	rep(i, n)	dat[i] = mp(min(x[i], y[i]), max(x[i], y[i]));
	sort(dat.begin(), dat.end());
	vint r(n), b(n);
	rep(i, n)	r[i] = dat[i].fst, b[i] = dat[i].scn;
	segtree red(n, r), blue(n, b);
	ll ret = 1e18;
	rep(i, n) {//[0,i)をreverseする
		ll rbig = max(red.getmax(0, red.N, 0, i, 0), blue.getmax(0, blue.N, i, n, 0));
		ll rsml = min(red.getmin(0, red.N, 0, i, 0), blue.getmin(0, blue.N, i, n, 0));
		ll bbig = max(blue.getmax(0, blue.N, 0, i, 0), red.getmax(0, red.N, i, n, 0));
		ll bsml = min(blue.getmin(0, blue.N, 0, i, 0), red.getmin(0, red.N, i, n, 0));
		ret = min(ret, (bbig - bsml)*(rbig - rsml));
	}
	return ret;
}

int main() {
	cin >> n;
	rep(i, n)	cin >> x[i] >> y[i];
	ll ret1 = solve1();
	ll ret2 = solve2();
	cout << min(ret1,ret2) << endl;
	return 0;
}