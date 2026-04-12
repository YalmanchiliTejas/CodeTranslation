#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[3030][3030];
ll sum[3030];

int main(){
  int n;
  cin>>n;
  ll a[n+1]={};
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }

  for(int i=1;i<=n;i++){
    dp[i][i]=a[i];
  }

  for(int len=1;len<n;len++){
    for(int l=1;l+len<=n;l++){
      int r=l+len;
      dp[l][r]=max(a[l]+sum[r]-sum[l]-dp[l+1][r],a[r]+sum[r-1]-sum[l-1]-dp[l][r-1]);
    }
  }

  cout<<dp[1][n]-(sum[n]-dp[1][n])<<endl;



  return 0;
}
