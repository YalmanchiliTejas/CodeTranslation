// E - Almost Everywhere Zero
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
string N;
int K;
int lt = 0, eq = 1;//lt: <, eq: =
int dp[100+1][2][4+1];// digit DP, [|N|+1: 1 origin][lt|eq][k:0~3]

int main(){
	cin>>N>>K;
	int dn = N.size();
	dp[0][eq][0] = 1;
	rp(i,0,dn){
		int di = N[i] - '0';
		rp(k,0,4){
			dp[i+1][lt][k] = dp[i][lt][k] * 1 + dp[i][eq][k] * (di?1:0);
			if(k) dp[i+1][lt][k] += dp[i][lt][k-1] * 9 + dp[i][eq][k-1] * max(0,di-1);
			if(dp[i][eq][k]) dp[i+1][eq][k+(di>0)] = 1;
		}
	}
	cout<< dp[dn][lt][K] + dp[dn][eq][K] <<endl;
}