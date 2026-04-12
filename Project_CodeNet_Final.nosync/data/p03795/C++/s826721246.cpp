#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  ll n;
  cin >> n;

  ll ans = 800*n;
  ans -= (n/15)*200;

  cout << ans << endl;
  
  return 0;
}