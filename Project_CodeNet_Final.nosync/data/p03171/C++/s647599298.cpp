#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  vector<signed long long int> vect(n);
  for(int i=0;i<n;i++) cin>>vect[i];
  vector<vector<signed long long int>> dp(n,vector<signed long long int>(n));
  for(int i=0;i<n;i++) dp[i][i]=vect[i];
  for(int l=n-1;l>=0;l--){
    for(int r=l+1;r<n;r++){
      dp[l][r]=max(vect[l]-dp[l+1][r],vect[r]-dp[l][r-1]);
    }
  }
  cout<<dp[0][n-1];
  return 0;
}