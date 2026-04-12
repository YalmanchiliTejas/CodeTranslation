#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

cpp_int ModPow(cpp_int x, int n){
  cpp_int res = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      x *= x;
      n /= 2;
    } else {
      res *= x;
      --n;
    }
  }
  return res;
}

cpp_int rec(int n, const cpp_int& x) {
  if (n == 0) return x >= 0;
  if (x == 0) return 0;
  if (x == ModPow(2, n + 1) - 2) return ModPow(2, n);
  if (x < ModPow(2, n + 1) - 2) return rec(n - 1, x - 1);
  return ModPow(2, n) + rec(n - 1, x - ModPow(2, n + 1) + 1);
}

int main() {
  int n;
  cin >> n;
  cpp_int x;
  cin >> x;
  cout << rec(n, x - 1) << endl;
}
