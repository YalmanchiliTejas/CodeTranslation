#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  
  int tall = 0;
  int ans = 0;
  
  rep(i,n){
    if(v[i] >= tall){
      ans++;
      tall = v[i];
    }
  }
  cout << ans << endl;
}