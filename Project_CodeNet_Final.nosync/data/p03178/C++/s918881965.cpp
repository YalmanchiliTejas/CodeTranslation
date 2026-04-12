#include <iostream>
#include <string>
using namespace std;
long long dp[10010][110][2] = {},mod = 1000000007;
int main(){
	string k;
	int i,j,l,d;
	cin >> k >> d;
	for(i=1;i<=k[0]-'0';i++){
		if(k[0]-'0'==i) dp[0][i%d][1]++;
		else dp[0][i%d][0]++;
	}
	for(i=1;i<k.size();i++){
		for(j=1;j<=9;j++){
			dp[i][j%d][0]++;
		}
		for(j=0;j<=9;j++){
			for(l=0;l<d;l++){
				(dp[i][(j+l)%d][0] += dp[i-1][l][0]) %= mod;
				if((k[i]-'0')>=j) (dp[i][(j+l)%d][(k[i]-'0')==j] += dp[i-1][l][1]) %= mod;
			}
		}
	}
	cout << (dp[k.size()-1][0][0] + dp[k.size()-1][0][1])%mod << endl;
}