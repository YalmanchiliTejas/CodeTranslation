#include "bits/stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define en '\n'
#define pb push_back
#define mp make_pair

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;

struct aaa {
	aaa() {
		cin.tie(0);
		ios::sync_with_stdio(0);
		cout << fixed << setprecision(20);
	};
}aaaaa;

ll Len[51], Pat[51]; //長さとパティの数

ll f(ll k, ll x) { //レベルk, 下からx
	if (x == Len[k]) return Pat[k];

	ll ans = 0;
	x--;

	//下のk-1
	if (x > 0) {
		ll l = min(x, Len[k - 1]);
		ans += f(k - 1, l);
		x -= l;
	}

	//真ん中
	if (x > 0) {
		ans++;
		x--;
	}

	//上のk-1
	if (x > 0) {
		ll l = min(x, Len[k - 1]);
		ans += f(k - 1, l);
		x -= l;
	}

	return ans;
}

int main() {
	ll n, x;
	cin >> n >> x;

	Len[0] = Pat[0] = 1;
	for (int i = 1; i <= n; i++) {
		Len[i] = Len[i - 1] * 2 + 3;
		Pat[i] = Pat[i - 1] * 2 + 1;
	}

	cout << f(n, x) << en;
}