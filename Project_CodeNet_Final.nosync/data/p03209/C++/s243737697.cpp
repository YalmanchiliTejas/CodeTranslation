#include <iostream>

using namespace std;
using ll = long long;

ll hoge1(ll n) {
  static ll data[100] = {};
  if (data[n] != 0)
    return data[n];
  return data[n] = n == 0 ? 1 : 3 + 2 * hoge1(n-1);
}

ll hoge2(ll n, ll x) {
  if (n == 0)
    return 1;
  else if (x == 1)
    return 0;
  else if (x <= hoge1(n-1) + 1)
    return hoge2(n-1, x-1);
  else if (x == hoge1(n-1) + 2)
    return hoge2(n-1, hoge1(n-1)) + 1;
  else if (x <= 2 + 2 * hoge1(n-1))
    return hoge2(n-1, hoge1(n-1)) + hoge2(n-1, x - hoge1(n-1) - 2) + 1;
  else
    return hoge2(n-1, hoge1(n-1)) * 2 + 1;
}


int main() {
  ll n, x;
  cin >> n >> x;
  cout << hoge2(n, x) << endl;
}
