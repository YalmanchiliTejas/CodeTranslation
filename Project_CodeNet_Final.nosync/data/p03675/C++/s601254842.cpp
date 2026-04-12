#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> x, y;
	vector<int> a(N); rep(i, 0, N) {
		cin >> a[i];
		if (i % 2 == 0)x.emplace_back(a[i]);
		else y.emplace_back(a[i]);
	}
	if (N % 2 == 1) {
		reverse(all(x));
		x.insert(x.end(), y.begin(), y.end());
		cout << x[0]; rep(i, 1, x.size()) { cout << " " << x[i]; } cout << endl;
	}
	else {
		reverse(all(x));
		x.insert(x.end(), y.begin(), y.end());
		reverse(all(x));
		cout << x[0]; rep(i, 1, x.size()) { cout << " " << x[i]; } cout << endl;
	}

	return 0;
}