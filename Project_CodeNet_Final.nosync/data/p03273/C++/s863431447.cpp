#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	rep(i, h)rep(j, w) cin >> a[i][j];
	vector<int> resh(h);
	rep(i, h) {
		int b = 0;
		rep(j, w) {
			if (a[i][j] == '#') b++;
		}
		if(b == 0)resh[i] = 1;
	}
	vector<int> resw(w);
	rep(i, w) {
		int b = 0;
		rep(j, h) {
			if (a[j][i] == '#') b++;
		}
		if (b == 0)resw[i] = 1;
	}
	rep(i, h) {
		if (resh[i] == 1) continue;
		rep(j, w) {
			if (resw[j] == 1)continue;
			cout << a[i][j];
		}
		cout << endl;
	}
 	return 0;
}