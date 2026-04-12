#include <iostream>
#include <string>
#define llint long long 
#define mod 1000000007

using namespace std;

llint d, n;
string s;
llint dp[10005][105][3];

int main(void)
{
	cin >> s;
	cin >> d;
	n = s.size();
	
	dp[0][0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 10; l++){
					int nk = k;
					if(i == 0 && l == 0) continue;
					if(k == 0 && l > s[i]-'0') nk = 1;
					if(k == 0 && l < s[i]-'0') nk = 2;
					dp[i+1][(j+l)%d][nk] += dp[i][j][k];
					dp[i+1][(j+l)%d][nk] %= mod;
				}
			}
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		for(int k = 0; k < 3; k++){
			if(i == n && k == 1) continue;
			ans += dp[i][0][k], ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}