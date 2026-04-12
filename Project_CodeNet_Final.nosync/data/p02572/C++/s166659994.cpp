#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n; cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = 0;
  for(int i=0; i<n; i++) {
    sum -= a[i];
    ans += ((sum%mod) * a[i])%mod;
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}

// EOF