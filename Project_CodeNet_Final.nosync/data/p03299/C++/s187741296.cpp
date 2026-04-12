#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 105;

int n, a[N], b[N], m, na[N];
map<int, int> ba;

const int mo = 1e9 + 7;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

ll qu(int x, int y) {
	return (ksm(2, y + 1) - ksm(2, x) + mo) % mo;
}

ll a2[N];
ll f[N][N];

void add(ll &x, ll y) {
	(x += y) %= mo;
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - (b + 1);
	fo(i, 1, m) ba[b[i]] = i;
	fo(i, 1, n) na[i] = ba[a[i]];
	b[m + 1] = 2e9; f[0][m + 1] = 1;
	fo(i, 1, n) {
		fo(j, 1, m + 1) if(f[i - 1][j]) {
			if(a[i - 1] <= a[i]) {
				if(b[j] <= a[i]) {
					add(f[i][j], f[i - 1][j] * ksm(2, a[i] - a[i - 1]));
				} else {
					fo(k, na[i - 1] + 1, na[i]) {
						int x = b[k - 1] + 1, y = b[k];
						if(x == 1) x ++;
						if(x <= y)
						add(f[i][k], f[i - 1][j] * qu(a[i] - y + 1, a[i] - x + 1)) ;
					}
					add(f[i][m + 1], f[i - 1][j] * 2);
				}
			} else {
				if(b[j] <= a[i]) {
					add(f[i][j], f[i - 1][j]);
				} else {
					add(f[i][m + 1], f[i - 1][j] * 2);
				}
			}
		}
	}
	ll ans = 0;
	fo(j, 1, m + 1) ans = (ans + f[n][j]) % mo;
	pp("%lld\n", ans);
}
