#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }

  ll ans = 0;
  for(int i = 0; i < n-1; i++){
    sum -= a[i];
    ll modSum = sum % 1000000007;
    ll tmp = ( a[i] * modSum) % 1000000007;
    ans = (ans + tmp) % 1000000007;
  }
  cout << ans  << endl;
}
