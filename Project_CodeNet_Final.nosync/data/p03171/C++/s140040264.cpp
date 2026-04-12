#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++){
      cin>>v[i];
  }
  vector<vector<ll>> dp(n,vector<ll>(n,0));
  for(int i=0;i<n;i++){
      dp[i][i] = v[i];
  }
  for(int len=2;len<=v.size();len++){
      for(int i=0;i<v.size()-len+1;i++){
          int j = i+len-1;
          dp[i][j] = max((v[i]-dp[i+1][j]),v[j]-dp[i][j-1]);
      }
  }
  cout<<dp[0][n-1];
}