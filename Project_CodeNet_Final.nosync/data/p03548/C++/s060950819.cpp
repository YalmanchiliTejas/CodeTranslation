#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll x, y, z;
  cin >> x >> y >> z;
  
  x -= z;
  
  cout << x/(y+z) << "\n";

}
