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
const int maxn = 300010, p = 1e9+7;
ll pf[maxn], a[maxn], n;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;++i)
		cin >> a[i], pf[i] = pf[i-1] + a[i], pf[i] %= p;
	ll res = 0;
	for (int i = 2;i <= n;++i)
		res = (res + a[i] * pf[i-1]) % p;
	cout << res << '\n';
}

