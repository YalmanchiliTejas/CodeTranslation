#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)1e5 + 5;
const dbl pi = acos(-1);

void add(ll a, ll& b) {
	b += a;
	if (b >= mod)
		b -= mod;
}

ll pw(ll x, ll y) {
	if (y == 0)
		return 1;
	if (y & 1)
		return pw(x, y - 1) * x % mod;
	x = pw(x, y / 2);
	return x * x % mod;
}

ll d[105][105];
int n, h[105], sh[105], pos[105];

int main() {
//	fin("t.in");
	sync;
	cin >> n;
	E(i, 1, n) {
		cin >> h[i];
//		h[i] = 100 * i;
		sh[i] = h[i];
	}
	sh[0] = h[0] = 1;
	sort(sh, sh + n + 1);
	E(i, 0, n) {
		pos[i] = 0;
		while (sh[pos[i]] < h[i])
			++pos[i];
	}

	clean(d);
	d[0][0] = 1;
	F(i, 0, n) {
		E(j, 0, n) {
			if (d[i][j] == 0)
				cont;
			if (h[i + 1] <= h[i]) {
				if (j < pos[i + 1])
					add(d[i][j], d[i + 1][j]);
				else
					add(2ll * d[i][j] % mod, d[i + 1][pos[i + 1]]);
			} else {
				if (j < pos[i]) {
					add(pw(2, h[i + 1] - h[i]) * d[i][j] % mod, d[i + 1][j]);
				} else {
					F(k, j, pos[i + 1]) {
						ll x = 2ll * (pw(2, h[i + 1] - sh[k]) - pw(2, h[i + 1] - sh[k + 1])) * d[i][j];
						x %= mod;
						x += mod;
						x %= mod;
						add(x, d[i + 1][k]);
					}
					add(2ll * d[i][j] % mod, d[i + 1][pos[i + 1]]);
				}
			}
		}

	}


	ll ans = 0;
	E(i, 0, n) {
//		cout << i << " " << d[2][i] << endl;
		add(d[n][i], ans);
	}
	cout << ans << endl;
	return 0;
}