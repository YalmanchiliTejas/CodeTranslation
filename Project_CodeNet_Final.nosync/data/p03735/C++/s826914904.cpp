#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define rep(i,a,b) for(int i=int(a),nn=int(b);i<=nn;++i)
#define vep(i,a,b) for(int i=int(a),nn=int(b);i>=nn;--i)
#define xep(i,b) for(int i=0,nn=int(b);i<nn;++i)

const int N = 200100;
typedef long long ll;
const int inf = 1000000005;
ll as;
int ano, x[N], y[N] ;
int n, od[N];

template <typename tp> inline tp imn(tp a, tp b) { return a<b?a:b;}
template <typename tp> inline tp imx(tp a, tp b) { return a>b?a:b;}
inline bool cmp(int a, int b) {
  	return x[a] == x[b] ? y[a] < y[b] : x[a] < x[b];
}
int main() {
  	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int mx = 0, mn = inf;
	rep(i, 1, n) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
		mx = imx(y[i], mx), mn = imn(y[i], mn);
		od[i] = i;
	}
	sort(od+1, od+1+n, cmp);
	as = (ll) (mx-mn) * (x[od[n]] - x[od[1]]);
	ano = mx - x[od[1]];
	mx = x[od[n]], mn = inf;
	rep(i, 1, n-1) {
	  	mx = imx(mx, y[od[i]]);
		mn = imn(mn, y[od[i]]);
		as = imn(as, (ll)(mx-imn(mn, x[od[i+1]]))*ano);
	}
	return printf("%lld\n", as), 0;
}

