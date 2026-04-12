#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];

	vector<string> ans(h, "");
	rep(i, w) {
		bool black = false;
		rep(j, h) {
			if (a[j][i] == '#') {
				black = true;
				break;
			}
		}
		if (black) {
			rep(j, h) ans[j] += a[j][i];
		}
	}

	rep(i, h) {
		bool black = false;
		rep(j, ans[0].size()) {
			if (ans[i][j] == '#') {
				black = true;
				break;
			}
		}
		if (black) {
			cout << ans[i] << endl;
		}
	}

}