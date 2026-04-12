#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1e9+7;

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0, sum = 0;
  for(int i = 0; i < n-1; i++){
    sum += a[i];
    sum %= MOD;
    ans += sum * a[i+1];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}