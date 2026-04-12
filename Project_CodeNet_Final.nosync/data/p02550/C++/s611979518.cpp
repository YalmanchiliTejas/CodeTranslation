#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;
typedef pair<pi, pi> pipi;
#define f first
#define s second
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<pii> vpii;
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define disc(v) sort(all(v)); v.resize(unique(all(v)) - v.begin());
#define INF (ll) 1e9 + 100
#define LLINF (ll) 1e18
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sandybridge __attribute__((optimize("Ofast"), target("arch=sandybridge")))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss

ll n, x, m, vis[100005], ans, cur;
vi v;

int main() {
	fastio; cin >> n >> x >> m;
	FOR(i, 1, n) {
		if (vis[x] != 0) {
			ans += accumulate(v.begin(), v.begin()+vis[x]-1, 0ll);
			ll cyc = i - vis[x];
			ans += (n-vis[x]+1)/cyc * accumulate(v.begin()+vis[x]-1, v.end(), 0ll);
			ans += accumulate(v.begin()+vis[x]-1, v.begin()+vis[x]-1 + ((n-vis[x]+1) % cyc), 0);
			break;
		} else {
			vis[x] = i;
			cur += x;
			v.pb(x);
			x = (x*x) % m;
		}
	}
	cout << (ans == 0 ? cur : ans);
}
