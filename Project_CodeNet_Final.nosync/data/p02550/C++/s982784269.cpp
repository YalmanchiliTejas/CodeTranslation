#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
using ll = long long;
#ifdef KEV
#define DE(i, e) cerr << #i << ' ' << i << e
void debug(auto L, auto R) { while (L < R) cerr << *L << " \n"[L+1==R], ++L; }
#else
#define DE(...) 0
void debug(...) {}
#endif
const int maxn = 300010, x = 213247, p = 1e9+7;
ll v[maxn], hs[maxn], n, k, m, pf[maxn], po[maxn]{1};
ll res;
ll gh(int l, int len) {
	return (hs[l+len-1] - hs[l-1] * po[len] % p + p) % p;
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> v[1] >> m;
	for (int i = 2;i <= m+m;++i) 
		v[i] = v[i-1] * v[i-1] % m;
	for (int i = 1;i <= m+m;++i) {
		hs[i] = (hs[i-1] * x + v[i]) % p;
		pf[i] = pf[i-1] + v[i];
		po[i] = po[i-1] * x % p;
	}
	if (n <= m+m) 
		return cout << pf[n] << '\n', 0;
	if (v[m] == 0) 
		return cout << pf[m] << '\n', 0;


	int cy = -1;
	for (int len = 1;len <= m;++len) {
		if (gh(m+m-len+1, len) == gh(m+m-len-len+1, len)) {
			cy = len;
			break;
		}
	}
	DE(cy, '\n');
	assert(cy != -1);
	int e = m+m;
	ll over = n - e;
	ll sum = pf[e] - pf[e-cy];
	res = pf[e] + over / cy * sum;
	over %= cy;
	DE(over, '\n');
	for (int h = 0, i = m+m-cy+1;h < over;++h, ++i) {
		res += v[i];
		//cerr << i << ' ';
	}
	cout << res << '\n';
}
