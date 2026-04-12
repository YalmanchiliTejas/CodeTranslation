#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[3005][3005];//dp[i][j] -> we get j heads from first i coins 

int main(){
  int n;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++){
  	cin>>a[i];
    dp[i][i]=a[i];
  }
  for(int i=n-1;i>=0;--i){
  	for(int j=i+1;j<n;++j){
    	dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    }
  }
  cout<<dp[0][n-1];
  return 0;
}