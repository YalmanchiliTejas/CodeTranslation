#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#define llint long long

using namespace std;

string s;
llint m;
llint dp[105][4][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> m;
	reverse(s.begin(), s.end());
	llint n = s.size();
	
	dp[n][0][0] = 1;
	for(int i = n; i > 0; i--){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 10; l++){
					int nj = j, nk = k;
					if(l != 0) nj++;
					if(nj > m) continue;
					if(s[i-1]-'0' < l && k == 0) continue;
					if(s[i-1]-'0' > l) nk = 1;
					dp[i-1][nj][nk] += dp[i][j][k];
					
				}
			}
		}
	}
	cout << dp[0][m][0] + dp[0][m][1] << endl;
	
	return 0;
}