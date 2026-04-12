#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A,B,C,D,H,K,L,M,N,T,W,X;
  string S;
  cin >> N;
  vector<long long> vec(N);
  long long dp[N][5];
  for (int i=0;i<N;i++) {cin >> vec.at(i);}
  
  A=0;
  
  if (N%2==0) {
    dp[1][0]=vec[0];
	dp[1][1]=vec[1];
	if (N>2) {
	  for (int j=2;j<N/2+1;j++) {
	    dp[j][0]=dp[j-1][0]+vec[j*2-2];
	    dp[j][1]=max(dp[j-1][0]+vec[j*2-1],dp[j-1][1]+vec[j*2-1]);
	  }
	  cout << max(dp[N/2][0],dp[N/2][1]) << endl;
	  }
	else {cout << max(vec[0],vec[1]) << endl;}
	}
  else {
    dp[2][0]=max(vec[0],vec[1]);
	dp[2][1]=vec[2];
	dp[2][2]=vec[0]+vec[2];
	if (N>3) {
	  for (int i=3;i<(N+1)/2+1;i++) {
	    dp[i][0]=max(dp[i-1][0]+vec[i*2-3],dp[i-1][2]);
		dp[i][1]=max(dp[i-1][0]+vec[i*2-2],dp[i-1][1]+vec[i*2-2]);
		dp[i][2]=dp[i-1][2]+vec[i*2-2];
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	  }
	  cout << max(dp[(N+1)/2][0],dp[(N+1)/2][1]) << endl;
	}
	else {cout << max(max(vec[0],vec[1]),vec[2]) << endl;}
  }
  
}