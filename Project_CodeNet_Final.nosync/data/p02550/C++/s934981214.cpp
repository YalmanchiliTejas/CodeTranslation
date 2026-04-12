/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

ll n;
int x, m;
vector<int> ps;
int l, r;
int lgl[1 << 17];

int main() {
	cin >> n >> x >> m;
	memset(lgl, -1, sizeof(lgl));
	int now = x; ps.pub(x);
	while(1) {
		now = 1ll * now * now % m;
		if(~lgl[now]) {
			l = lgl[now];
			r = SZ(ps);
			break;
		}
		lgl[now] = SZ(ps);
		ps.pub(now);
	}
	if(n < r) {
		ll ans = 0;
		loop(i, n) ans += ps[i];
		cout << ans << endl;
		return 0;
	}
	ll lh = 0, rh = 0;
	loop(i, l) lh += ps[i];
	loop(i, r) rh += ps[i];
	rh -= lh;
	ll ans = lh + rh * ((n - l) / (r - l));
	int rm = (n - l) % (r - l);
	loop(i, rm) ans += ps[i + l];
	cout << ans << endl;
	return 0;
}
