#include <bits/stdc++.h>

using namespace std;
const long long INF=1e9+7;
long long n, a[100009];
long long dp[100009];

int main(){
  cin >> n;
  fill(dp, dp+n+1, INF);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=n-1;i>=0;i--){
    *upper_bound(dp, dp+n, a[i])=a[i];
  }
  for(int i=0;i<=n;i++){
    if(dp[i]==INF){
      cout << i << endl;
      return 0;
    }
  }
}

