#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define M 1000000007

int main(){
	ll k,i,j,n,ai,aj,sum=0;
  cin>>n;
  ll arr[n];
  for(i=0;i<n;i++){
   cin>>arr[i];
    sum+=arr[i];
  }
   
  ll dp[n][n];
  
  for(k=0;k<n;k++){
  	for(i=0,j=k;j<n;j++,i++){
  		if(i==j)dp[i][j]=arr[i];
      else if(j==i+1)dp[i][j]=max(arr[i],arr[j]);
      else{
      	ai=arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
      	aj=arr[j]+min(dp[i][j-2],dp[i+1][j-1]);
      	dp[i][j]=max(ai,aj);
      }
      
    }
  }
  cout<<(2*dp[0][n-1])-sum<<"\n";
  
  return 0;
}