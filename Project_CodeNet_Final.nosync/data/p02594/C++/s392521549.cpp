#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define fore(i,a,b) for(int i = a; i < (b); i++)
#define fr(i,a,b) for(int i = a - 1; i >= b; i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define N 300005
#define inf 2000000000
#define EPS 1e-6
#define MOD (ll)1e15
#define __builtin_popcount(x) __popcnt(x)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll binpow(ll x, ll p)
{
	if (p == 0)
		return 1;
	if (p % 2)
		return (binpow(x, p - 1) * x) % MOD;
	else
	{
		ll xx = binpow(x, p / 2);
		return (xx * xx) % MOD;
	}
}

inline void solve()
{
	int x;
	cin >> x;
	if (x >= 30)
		cout << "Yes";
	else
		cout << "No";
}

int main()
{
	fast;
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*int q = 1;
	//cin >> q;
	while (q--)
	{*/
		solve();
		//cout << '\n';
	//}
}