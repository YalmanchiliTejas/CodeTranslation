#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	cin.exceptions(cin.failbit);

	ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;

	ll both = min(x, y); x -= both, y -= both;
	ll cost = 0;

	cost += min(a + b, 2 * c) * both;
	cost += min(a, 2 * c) * x;
	cost += min(b, 2 * c) * y;

	cout << cost << endl;
}
