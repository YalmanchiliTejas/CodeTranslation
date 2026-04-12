#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
struct pp{
  ll first;
  ll second;
};
pp dp[3010][3010];
int main(){
  int n;
  cin >> n;
  vector<ll> a(n,0);
  ll sum = (ll)0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    dp[i][i].first = a[i];
    dp[i][i].second = 0;
  }

  for(int len = 1;len<n;len++){
    for(int i=0;i<n-len;i++){
      int j=i+len;
      if(a[i]+dp[i+1][j].second>a[j]+dp[i][j-1].second){
        dp[i][j].first = a[i]+dp[i+1][j].second;
        dp[i][j].second = dp[i+1][j].first;
      }
      else{
        dp[i][j].first = a[j]+dp[i][j-1].second;
        dp[i][j].second = dp[i][j-1].first;
      }
    }
  }
  cout<<(dp[0][n-1].first-dp[0][n-1].second)<<endl;
}
