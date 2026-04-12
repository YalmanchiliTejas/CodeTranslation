#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const int64_t LINF=8931145141919364364,LMOD=998244353;
// const int dy[]={0,-1,0,1,1,-1,-1,1};
// const int dx[]={1,0,-1,0,1,1,-1,-1};

int64_t C(int64_t n, int64_t k) {
	int64_t ret = 1;
	for(int64_t i = 1; i <= k; ++i) {
		ret *= (n + 1 - i);
		ret /= i;
	}
	return ret;
}

int main() {
	string s; cin >> s;
	int sn = s.size();
	int k; cin >> k;
	int64_t ans[sn + 1][k + 1][2] = {};
	ans[0][k][0] = 1;
	for(int i = 1; i <= sn; ++i) {
		int c = s[i - 1] - '0';
		for(int x = 0; x <= k; ++x) {
			ans[i][x][1] += ans[i - 1][x][1];
			if(c == 0) {
				ans[i][x][0] += ans[i - 1][x][0];
			} else {
				ans[i][x][1] += ans[i - 1][x][0];
			}
			for(int j = 1; j <= 9; ++j) {
				if(x + 1 <= k) ans[i][x][1] += ans[i - 1][x + 1][1];
				if(j < c) {
					if(x + 1 <= k) ans[i][x][1] += ans[i - 1][x + 1][0];
				} else if(j == c) {
					if(x + 1 <= k) ans[i][x][0] += ans[i - 1][x + 1][0];
				}
			}
		}
	}
	// for(int i = 0; i <= sn; ++i) {
	// 	for(int j = 0; j <= k; ++j) {
	// 		for(int y = 0; y < 2; ++y) {
	// 			cerr << ans[i][j][y] << '\n';
	// 		}
	// 	}
	// }
	cout << ans[sn][0][0] + ans[sn][0][1] << '\n';
	return 0;
}