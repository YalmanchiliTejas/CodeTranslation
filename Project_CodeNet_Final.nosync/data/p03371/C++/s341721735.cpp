#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(obj) obj.begin(), obj.end()
#define db(x) cerr << #x << ":" << x << " "
#define dbl(x) cerr << #x << ":" << x << "\n"
#define dbv(vec) cerr << #vec << ":"; for (auto e : vec) cerr << e << " "; cout << "\n"
#define dbgvv(vv) cerr << #vv << ":\n"; for (auto vec : vv) { for (auto e : vec) cerr << e << " "; cerr << endl; }
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define Yn(f) cout << (f ? "Yes" : "No") << endl
#define yn(f) cout << (f ? "yes" : "no") << endl
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main () {
	int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
	int ans = 0;
	if (A + B <= 2 * C) {
		ans += (A + B) * min(X, Y);
	} else {
		ans += 2 * C * min(X, Y);
	}
	if (X >= Y) {
		X -= Y; Y = 0;
	} else {
		Y -= X; X = 0;
	}
	if (X > 0) {
		if (A <= 2 * C) {
			ans += A * X;
		} else {
			ans += 2 * C * X;
		}
	} else if (Y > 0) {
		if (B <= 2 * C) {
			ans += B * Y;
		} else {
			ans += 2 * C * Y;
		}
	} 
	cout << ans << endl;
}