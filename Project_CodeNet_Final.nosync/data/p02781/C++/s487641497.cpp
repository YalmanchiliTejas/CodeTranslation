#include <bits/stdc++.h>
using namespace std;

int main(){
	string S;
	int K;
	cin >> S >> K;
	
	int len=S.size();
	int dp[len+1][2][K+1];
	for(int i=0;i<len+1;i++)for(int j=0;j<K+1;j++)dp[i][0][j]=0;
	for(int i=0;i<len+1;i++)for(int j=0;j<K+1;j++)dp[i][1][j]=0;
	
	dp[0][0][0]=1;
	
	for(int i=0;i<len;i++){
		for(int smaller=0;smaller<2;smaller++){
			for(int j=0;j<K+1;j++){
				for(int x=0;x<=(smaller ? 9:(int)(S[i]-'0'));x++){
					if(x>0 && j<K)dp[i+1][smaller || (x<(int)(S[i]-'0'))][j+1]+=dp[i][smaller][j];
					if(x==0)dp[i+1][smaller || (x<(int)(S[i]-'0'))][j]+=dp[i][smaller][j];
				}
			}
		}
	}
	cout << dp[len][0][K]+dp[len][1][K] << endl;
	return 0;
}