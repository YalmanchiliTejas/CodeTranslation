#include<bits/stdc++.h>
#define int long long 
using namespace std; 

int32_t main(){
	
  int n; cin>>n;
  int a[n+1];
  int dp[n+1][n+1];
  memset(dp,0,sizeof(dp));
  
  for(int i = 1; i<=n; i++)cin>>a[i];

  for(int len = 1; len<=n; len++){
  	for(int l = 1; l<=n-len+1; l++){
    	int r = l + len -1;
        if(len == 1)
          dp[l][r]=a[l];
        else
          dp[l][r] = max(a[l] -dp[l+1][r] , a[r] - dp[l][r-1]);
    }
  }
  	cout<<dp[1][n]<<endl;
	return 0;
}

