#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long a[n], b[n]={0};
  for(int i=0; i<n; i++) {
    cin >> a[i];
    b[0]=a[0];
    if(0<i) {
      b[i]+=b[i-1]+a[i];
      b[i]%=1000000007;
    }
  }
  long long ans=0;
  for(int i=1; i<n; i++) {
    ans+=a[i]*b[i-1];
    ans%=1000000007;
  }
  cout << ans << endl;
  return 0;
}