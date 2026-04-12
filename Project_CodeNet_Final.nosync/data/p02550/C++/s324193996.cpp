#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1<<20;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mod;
ll n, x, f[maxn], seen[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x >> mod;
	f[1] = x;
	int p = 2;
	ll sm = x;
	seen[x] = 1;
	while(true) {
		if(p > n) {
			cout << sm << '\n';
			return 0;
		}
		f[p] = f[p-1]*1ll*f[p-1]%mod;
		if(seen[f[p]]) break;
		sm += f[p];
		seen[f[p]] = p;
		p++;
	}
	int ST = seen[f[p]];
	int LEN = p - ST;
	//cout << ST << " " << LEN << " " << n%LEN << endl;
	n -= p-1;
	ll ans = sm;
	ll ful = 0;
	for(int i = ST; i < p; i++) {
		ful += f[i];
	}
	ans += ful*1ll*(n/LEN);
	n %= LEN;
	for(int i = 0; i < n; i++)
		ans += f[ST+i];
	cout << ans << '\n';
}
