// E - Almost Everywhere Zero
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
string N;
int K;
int lt = 0, eq = 1;//lt: <, eq: =
int dp[101][2][4];// digit DP, [|N|+1: 1 origin][lt|eq][k:0~3]

int main(){
	cin>>N>>K;
	N = "0" + N;
	int dn = N.size();
	int di = N[0] - '0';
	dp[0][eq][0] = 1;
	rp(i,1,dn){
		di = N[i] - '0';
		rp(k,0,4){
			// lt
			dp[i][lt][k] = dp[i-1][lt][k] * 1 + dp[i-1][eq][k] * (di?1:0);
			if(k) dp[i][lt][k] += dp[i-1][lt][k-1] * 9 + dp[i-1][eq][k-1] * max(0,di-1);
			// eq
			if(dp[i-1][eq][k]) dp[i][eq][k+(di>0)] = 1;
		}
	}
	cout<< dp[dn-1][lt][K] + dp[dn-1][eq][K] <<endl;
}