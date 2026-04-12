#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define DEC(i, a, b) for(int i = (int)a; i >= (int)b; i--)
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss

int main() {
	fastio; int x; cin >> x;
  cout << (x >= 30 ? "Yes" : "No");
}
