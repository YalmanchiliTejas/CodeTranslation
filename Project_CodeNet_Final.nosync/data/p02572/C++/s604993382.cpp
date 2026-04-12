#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REP_REV(i,a,b) for (int i = a; i >= b; i--)
#define what_is(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;

ll MOD = 1e9 + 7;

struct Rect {
	ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	ll area() { return (x2 - x1) * (y2 - y1); }
};

Rect intersect(Rect p, Rect q) {
	Rect inter;
	inter.x1 = max(p.x1, q.x1);
	inter.y1 = max(p.y1, q.y1);
	inter.x2 = min(p.x2, q.x2);
	inter.y2 = min(p.y2, q.y2);
	if (inter.x1 >= inter.x2 || inter.y1 >= inter.y2) {
		Rect empty;
		return empty;
	}
	return inter;
}

bool iscovered(int x, int y, int x1, int y1, int x2, int y2) {
	return (x <= x2 && x >= x1 && y <= y2 && y >= y1);
}

void solve() {
	ll n; cin >> n;
	vl a(n);
	REP(i, 0, n - 1) cin >> a[i];
	ll sum = 0;
	REP(i, 0, n - 1) sum += a[i];
	ll ans = 0;
	REP(i, 0, n - 1) {
		sum -= a[i];
		ans += (sum % MOD * a[i]) % MOD;
		ans %= MOD;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("billboard.in", "r", stdin);
	//freopen("billboard.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ll t; cin >> t;
	//while (t--)
	solve();
	return 0;
}