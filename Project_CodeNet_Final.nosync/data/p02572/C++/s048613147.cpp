#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define cs const 
#define fr first 
#define se second
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define low(i) (i&(-i))
#define par pair<int,int>
#define cn(x) memset(x, 0, sizeof(x))
#define rep(i, x, y) for(int i=x; i<=y; ++i)
#define sep(i, x, y) for(int i=x; i>=y; --i)
#define fore(i, x) for(int i=fir[x]; i; i=nex[i])

cs int G = 3;
cs int ff = 2e6 + 1;
cs int inf = 1e9 + 1;
cs int base = 2333;
cs int mod = 1e9 + 7;

int n, a[ff], top, ans;
signed main()
{
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	int s = 0;
	rep(i, 1, n) (ans += a[i] * s % mod) %= mod, (s += a[i]) %= mod;
	cout << ans;
}