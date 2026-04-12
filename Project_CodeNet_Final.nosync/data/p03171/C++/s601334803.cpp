#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
  cin>>n;
  long long int a[n];
  long long int dp[n][n];
  long long int sum=0;
  for(int i=0;i<n;i++){
    	cin>>a[i];
    dp[i][i]=a[i];
    sum+=a[i];
    }
     for(int len=2;len<=n;len++){
	for(int i=0;i<n-len+1;i++){
      int j=i+len-1;
      if(i+1==j)
        dp[i][j]=max(a[i],a[j]);
      else
        dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
    }
    }
  
  cout<<2*dp[0][n-1]-sum<<endl;
}
