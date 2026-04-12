#include <iostream>

using namespace std;
long long dp[110][5][2];
int main(){
	int i,j,l,k;
	string s;
	cin >> s >> k;
	for(j=1;j<=s[0] - '0';j++){
		if(j<s[0] - '0') dp[0][1][0] += 1;
		else dp[0][1][1] += 1;
	}
	for(i=1;i<s.size();i++){
		for(j=1;j<=9;j++){
			dp[i][1][0] += 1;
		}
		for(j=0;j<=9;j++){
			for(l=0;l<=3;l++){
				if(j==0){
					dp[i][l][0] += dp[i - 1][l][0];
					if(s[i]=='0') dp[i][l][1] += dp[i - 1][l][1];
					else dp[i][l][0] += dp[i - 1][l][1];
				}else{
					dp[i][l + 1][0] += dp[i - 1][l][0];
					if(j<s[i] - '0') dp[i][l + 1][0] += dp[i - 1][l][1];
					if(j==s[i] - '0') dp[i][l + 1][1] += dp[i - 1][l][1];
				}
			}
		}
	}
	cout << dp[s.size() - 1][k][1] +  dp[s.size() - 1][k][0] << endl;
}