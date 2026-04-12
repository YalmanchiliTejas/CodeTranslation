#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
int main() {
  LL n,ans=0; cin>>n;
  vector<LL> a(n); for(LL i=0;i<n;i++) cin>>a[i];
  LL subSum=0;
  for(int i=0;i<n-1;i++){
    subSum+=a[i];
    subSum%=MOD;
    ans+=subSum*a[i+1];
    ans%=MOD;
  }
  cout<<ans;
}