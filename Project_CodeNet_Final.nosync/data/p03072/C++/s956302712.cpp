#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;
typedef vector<ll> vint;
int main() {
  ll N;
  cin >> N;
  vint v(N);
  for (ll i=0;i<N;i++) cin >> v[i];
  
  ll ans=0,max=0;
  for (ll i=0;i<N;i++) {
    if (v[i]>=max) {
      ans++;
      max=v[i];
    }
  }
  
  
  
  cout << ans << endl;
}