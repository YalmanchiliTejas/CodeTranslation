#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll u = INF;
	for (int i = 0; i <= max(x,y); i++) {
		ll cc = c * i * 2;
		ll aa = max(0LL, (x - i)) * a;
		ll bb = max(0LL, (y - i)) * b;
		u = min(u, aa + bb + cc);
	}
	cout << u << endl;
	return 0;
}
