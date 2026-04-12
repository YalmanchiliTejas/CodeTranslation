#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	int rnow = 0;
	rep(i,H) {
		int l = -1, r = -1;
		bool flag = false;
		string s;
		cin >> s;
		rep(j,W){
			if (s[j] == '#') { l = j; break;}
		}
		rep(j,W){
			if (s[W-1-j] == '#') { r = W-1-j; break;}
		}
		if (l < rnow) flag = true;
		for (int j = l; j<=r; j++) {
			if (s[j] == '.') flag = true;
		}
		rnow = r;

		if (flag) {
			cout << "Impossible" << endl;
			return 0;
		}
	}

	cout << "Possible" << endl;

	return 0;
}
