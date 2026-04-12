#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
ll dp[10005][2][100];

int main(){
	
	string s;
	cin >> s;
	int d;
	cin >> d;
	
	// 1桁目
	int first = s[0] - '0';
	rep(i,first+1) dp[0][i < first][i%d]++;
	
	// 2桁目以降
	rep(i,s.size()-1) rep(j,2) rep(k,d){
		int lim = j? 9 : s[i+1] - '0';
		rep(next, lim+1){
			dp[i+1][j || next < lim][(k + next) % d] = (dp[i+1][j || next < lim][(k + next) % d] + dp[i][j][k]) % MOD;
		}
	}
	
	ll res = 0;
	rep(j,2) res = (res + dp[s.size()-1][j][0]) % MOD;
	
	cout << (res -1 + MOD) % MOD << endl; // 0を含んでいる為1減算
	
	return 0;
}