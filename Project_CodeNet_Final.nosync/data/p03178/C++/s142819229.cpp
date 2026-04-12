#include <bits/stdc++.h>

const int MOD = 1e9+7;
int main() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	int d;
	std::cin >> d;
	std::vector<std::vector<int> > dp(n,std::vector<int>(d,0));
	int xx = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<s[i]-'0';j++) {
			dp[i][(xx+j)%d] += 1;
		}
		xx = (xx+s[i]-'0')%d;
	}
	if(xx==0) dp[n-1][0]++;
	for(int i=1;i<n;i++) {
		for(int j=0;j<d;j++) {
			for(int k=0;k<10;k++) {
				dp[i][j]+=dp[i-1][((j-k)%d+d)%d];
				dp[i][j]%=MOD;
			}
		}
	}
	int ans = dp[n-1][0];
	std::cout << (ans+MOD-1)%MOD << '\n';

}
