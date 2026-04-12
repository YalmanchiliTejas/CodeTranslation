#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main() {
	string s;
	ll K;
	cin >> s >> K;
	int n = s.size();
	int dp[105][4][2] = {0};
	dp[0][0][0] = 1;	//空集合は一致している
	rep(i,n) rep(j,4) rep(k,2) {	// i:桁数、j:非ゼロの数、k:0だとnと一致、1だとn以下 
		int nd = s[i] - '0'; //nd:今の桁のnの数
		rep(d, 10){	// d:桁の数（0～9）
			int ni = i + 1, nj = j, nk = k;
			if(d != 0) nj++;	
			if(nj > K) continue;	//非ゼロの数がオーバー
			if(k == 0) {
				if(d > nd) continue;
				if(d < nd) nk = 1;
				// d = ndの場合、nkは0のまま
			}	//kが1の場合、残りの桁は何でもnk = 1
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	int ans = dp[n][K][0] + dp[n][K][1];
	cout << ans << endl;
	return 0;
}