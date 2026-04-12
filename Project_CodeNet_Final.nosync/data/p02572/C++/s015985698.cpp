#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  vector<int> ep(n);
  ep[n-1] = an[n-1];
  for(int i=n-2; i>=0; --i){
    ep[i] = ep[i+1] + an[i];
    ep[i] %= MOD;
  }
  ll ans = 0;
  for(int i=0; i<n-1; ++i){
    ans += (ll)an[i] *ep[i+1];
    ans %= MOD;
  }
  cout << ans << endl;
}