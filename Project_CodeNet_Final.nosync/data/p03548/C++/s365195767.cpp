#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll x,y,z;
  cin >> x >> y >> z;
  ll a = x/(y+z);
  if(a*(y+z)+z>x) cout << a-1 << endl;
  else cout << a << endl;
  
  return 0;
}