#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; ++i)cin>>a[i];

  long long dp[3010][3010]={0};

  for(int l=1; l<=n; ++l){
    for(int i=0; i+l<=n; ++i){
      int j=i+l;

      if((n-l)%2==0)dp[i][j]=max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
      else dp[i][j]=min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
    }
  }

  cout<<dp[0][n]<<endl;
}
