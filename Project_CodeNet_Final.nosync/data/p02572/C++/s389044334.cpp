#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0,mod=1000000007,asum=0,a;
  cin >> n;
  for(long i=0;i<n;i++) {
    cin >> a;
    ans=(a*asum%mod+ans)%mod;
    asum=(asum+a)%mod;
  }
  cout << ans << endl;
}