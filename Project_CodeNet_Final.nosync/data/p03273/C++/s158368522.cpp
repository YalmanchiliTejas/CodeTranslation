#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

string s[105];

signed main() {
	int h, w; cin >> h >> w;
	rep(i, h)cin >> s[i];
	vector<int>ah, aw;
	rep(i, h) {
		int c = 0;
		rep(j, w)if (s[i][j] == '#')c++;
		if (c)ah.push_back(i);
	}
	rep(i, w) {
		int c = 0;
		rep(j, h)if (s[j][i] == '#')c++;
		if (c)aw.push_back(i);
	}

	for (int e : ah) {
		for (int f : aw) {
			cout << s[e][f];
		}cout << endl;
	}
}