#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;
#define ll long long

int main () {
  ll n, x;
  cin >> n >> x;
  ll num[n + 1];
  num[0] = 1;
  num[1] = 5;
  ll p[n + 1];
  p[0] = 1;
  p[1] = 3;
  for (ll i = 2; i <= n; i++) {
    num[i] = 3 + num[i - 1] * 2;  
    p[i] = 1 + p[i - 1] * 2;
  }
  ll ans = 0;
  ll itr = n;
  while (1) {
    if (x == num[itr]) {
      ans = ans + p[itr];
      break;
    }
    if (x == 1 || x == 0) {
      break;
    }
    if (x >= 2 + num[itr - 1]) {
      ans = ans + p[itr - 1] + 1;
      x = x - (2 + num[itr - 1]);
      itr--;  
    }
    else {
      x--;
      itr--;  
    }
  }
  cout << ans << endl;
}