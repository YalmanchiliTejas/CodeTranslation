#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define ll long long int
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

  int main()
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    ll sum=0;
    F0R(i,n) {
      cin >> a[i];
      sum+=a[i];
      sum%=mod;
    }
    ll ans = 0;
    F0R(i,n) {
      sum-=a[i];
      if(sum<0) sum+=mod;
      ans += a[i]*sum;
      ans = ans % mod;
    }
    cout << ans;

    return 0;
  }