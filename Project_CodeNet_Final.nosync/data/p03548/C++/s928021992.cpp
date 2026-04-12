#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main(int argc, char *argv[]) {
  ll x, y, z;
  cin >> x >> y >> z;

  ll n = x / y;
  while (1) {
    ll m = (n*y) + ((n-1)*z) + (2*z);
    if (x >= m) {
      break;
    }
    n--;
  }
  cout << n << endl;

  return 0;
}