#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll MOD = 1e9+7;

int main() {
  int n;cin>>n;
  ll an[n];rep(i, n) cin>>an[i];
  ll sn[n+1];sn[n]=0;
  rep(i, n) {
    sn[n-1-i] = (sn[n-i] + an[n-1-i]) % MOD;
  }
  
  //rep(i, n) cout<<an[i]<<" ";cout<<endl;
  //rep(i, n+1) cout<<sn[i]<<" ";cout<<endl;
  
  ll ans = 0, s;
  rep(i, n-1) {
    s = (an[i] * sn[i+1]) % MOD;
    ans = (ans + s) % MOD;
  }
  cout<<ans;
}
