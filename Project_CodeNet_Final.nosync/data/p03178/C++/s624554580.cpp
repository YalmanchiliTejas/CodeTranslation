#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[2][102][2] = {};
inline void add(int &a, int b) {
	a = (a + b % mod) % mod;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; int d;
	cin >> s >> d;
	int len = s.length();
	dp[1][0][1] = 1;
	for (int i = 0; i < len; i++) {
		memset(dp[i&1], 0, sizeof(dp[i&1]));
		for (int j = 0; j < d; j++)
			for (int k = 0; k <= 9; k++)
				if(k < s[i]-'0')
					add(dp[i&1][(j+k)%d][0], dp[!(i&1)][j][0] + dp[!(i&1)][j][1]);
				else if (k == s[i]-'0')
					add(dp[i&1][(j+k)%d][0], dp[!(i&1)][j][0]),
					add(dp[i&1][(j+k)%d][1], dp[!(i&1)][j][1]);
				else
					add(dp[i&1][(j+k)%d][0], dp[!(i&1)][j][0]);
	}
	cout << (dp[!(len&1)][0][0] + dp[!(len&1)][0][1] - 1 + mod) % mod << "\n";
	return 0;
}