#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  long long n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<ll> dp(n);
  for(int i=0;i<n;i++){
    dp[i]=-1;
  }
  for(int i=0;i<n;i++){
    long long l=-1,r=n-1;
    while(r-l>1ll){
      long long mid=(r+l)/2ll;
      if(dp[mid]<a[i]){
        r=mid;
      }else{
        l=mid;
      }
    }
    dp[r]=a[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(dp[i]==-1) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
