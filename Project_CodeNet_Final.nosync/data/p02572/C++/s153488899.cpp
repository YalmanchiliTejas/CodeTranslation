#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD =  1e9+7;
ll POW(ll b, ll e) {
	ll res = 1;
	while(e) {
		if(e & 1) {
			res *= b; res %= MOD;
		}
		b *= b; b %= MOD;
		e/=2;
	}
	return res;
}
ll INV(ll a) {
	return POW(a, MOD-2);
}

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	ll sum = 0;
	ll squares = 0;
	M00(i, n) {
		ll x;
		cin >> x;
		sum += x; sum %= MOD;
		squares += x * x; squares %= MOD;
	}
	ll ans = (POW(sum, 2) - squares) * INV(2); ans %= MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}
