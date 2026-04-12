#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	vector<string> ans(h);
	int r = 0, c = 0;
	rep(i, h) {
		bool ok = true;
		rep(j, w) {
			if(a[i][j] == '#') ok = false;
		}
		if(!ok) {
			ans[r] = a[i];
			r++;
		}
	}
	vector<int> pri;
	rep(j, w) {
		bool ok = true;
		rep(i, h) {
			if(a[i][j] == '#') ok = false;
		}
		if(!ok) {
			pri.push_back(j);
		}
	}
	rep(i, r) {
		for(int j: pri) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}