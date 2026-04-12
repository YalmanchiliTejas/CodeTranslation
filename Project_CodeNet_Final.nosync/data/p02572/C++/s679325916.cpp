#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum;
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }

  vector<ll> b(n, sum);
  ll sum2 = 0;
  rep(i, n){
    sum2 += a[i];
    b[i] -= sum2;
    b[i] %= (1000000000+7);
  }

  int ans = 0;
  rep(i, n-1){
    //ans += (a[i] * b[i]);
    ans += (a[i] * b[i]) % (1000000000+7);
    ans %= (1000000000+7);
  }
  cout << ans << endl;
  return 0;
}