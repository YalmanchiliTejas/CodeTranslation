#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for(int i = (int)a; i >= (int)b; i--)
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;
#define f first
#define s second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<pii> vpii;
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()
#define disc(v) sort(all(v)); v.resize(unique(all(v)) - v.begin());
#define INF (int) 1e9 + 100
#define LLINF (ll) 1e18
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sandybridge __attribute__((optimize("Ofast"), target("arch=sandybridge")))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss

ll n, a, sum, mod = 1e9+7, ans;

int main() {
	fastio; cin >> n;
	FOR(i, 1, n) {
		cin >> a;
		ll cur = (sum * a) % mod;
		ans = (ans + cur) % mod;
		sum = (sum + a) % mod;
	}
	cout << ans;
}
