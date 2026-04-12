#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
	int h, w;
	cin >> h >> w;
	vector<string>a(h);
	rep(i, h)cin >> a[i];
	vector<bool>hei(h, false);
	vector<bool>wid(w, false);
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == '#') {
				hei[i] = true;
				wid[j] = true;
			}
		}
	}
	rep(i, h) {
		if (hei[i]) {
			rep(j, w) {
				if (wid[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
