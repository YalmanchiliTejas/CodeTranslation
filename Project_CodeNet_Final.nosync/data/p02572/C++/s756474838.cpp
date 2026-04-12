#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long ll;
typedef unsigned long long ull;

typedef V<int> vi;
typedef V<ll> vll;
typedef V<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define f(i,a) for(int i = 0 ; i < a ; i++)
#define fll(i,a) for(ll i = 0 ; i < a ;i++)
#define forab(i,a,b) for(int i = a ; i < b ; i++)
#define prec(x) cout<<fixed<<setprecision(x)
#define ff first
#define ss second

#define pb push_back
#define mp make_pair
#define numberofdigits(x) floor(log10(x)) + 1

const ll mod = 1e9 + 7;

ll binpow(ll a, long long b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a);
		a = (a * a);
		b >>= 1;
	}
	return res;
}



void solve() {

	ll n;
	cin >> n;

	ll a[n + 1];

	for (int i = 1 ; i <= n;  ++i)
		cin >> a[i];

	ll pref[n + 1];

	pref[1] = a[1] % mod;

	for (int i = 2 ; i <= n ; i++)
		pref[i] = (pref[i - 1] % mod + a[i] % mod) % mod;

	ll ans = 0;

	for (int i = 1 ; i <= n ; i++)
	{
		ans = (ans % mod + (((pref[n] - pref[i] + mod) % mod) * (a[i] % mod) % mod)) % mod;
	}

	cout << ans << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();
	return 0;
}



