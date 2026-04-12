#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main(){
  int n;
  cin >> n;
  int s[n];
  for(int i=0;i<n;i++) cin >> s[i];
  int ans=0;
  for(int i=1;i<n;i++){
    int l=i,r=n-1-i;
    int dp[n/i];
    dp[0]=0;
    int j=1;
    while(r>0&&l!=r&&l!=r+i&&r>i){
      dp[j]=dp[j-1]+s[l]+s[r];
      ans=max(ans,dp[j]);
      //cout << dp[j] << " ";
      j++;
      l+=i;
      r-=i;
    }
    //cout << endl;
  }
  cout << ans << endl;
}