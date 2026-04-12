#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
vector<int64> a, p;
int64 f(int64 N, int64 X) {
	if (N == 0) {
		if (X <= 0) return 0;
		else return 1;
	} else if (X <= 1 + a[N - 1]) {
		return f(N - 1, X - 1);
	} else {
		return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1]);
	}
}
void solve() {
	int64 N, X; cin >> N >> X;
	a.push_back(1); p.push_back(1);
	for(int i = 0; i < 50; ++i) {
		a.push_back(2 * a[i] + 3);
		p.push_back(2 * p[i] + 1);
	}
	int64 ans = f(N, X);
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}