#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
#define pb push_back

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	vector<string> n;
	rep(i, H) cin >> a[i];
	rep(i, H) {
		rep(j, W) {
			if (a[i][j] == '#') {
				n.pb(a[i]);
				break;
			}
		}
	}

	char ans[100][100];
	int w = 0;
	rep(i, W) {
		bool flag = false;
		rep(j, n.size()) {
			if (flag) ans[j][w] = n[j][i];
			if (n[j][i] == '#' && !flag) {
				flag = true;
				j = 0;
				ans[j][w] = n[j][i];
			}
		}
		w++;
		if (!flag)w--;
	}
	ll i = 0;
	ll j = 0;
	for (i; i < H; ++i) {
		j = 0;
		bool flag = false;
		if (ans[i][j] != '#' && ans[i][j] != '.') break;
		for (j; j < W; ++j) {
			if (ans[i][j] == '#' || ans[i][j] == '.') cout << ans[i][j];
			else {
				flag = true;
				cout << endl;
				break;
			}
		}
		if(!flag) cout << endl;
	}

}
