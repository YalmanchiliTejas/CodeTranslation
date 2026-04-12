#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

cpp_int Rec(int n, const cpp_int& x) {
  if (n == 0) return x >= 0;
  if (x == 0) return 0;
  cpp_int n_th_power_of_2 = (cpp_int)1 << n;
  if (x == 2 * n_th_power_of_2 - 2) return n_th_power_of_2;
  if (x <  2 * n_th_power_of_2 - 2) return Rec(n - 1, x - 1);
  return n_th_power_of_2 + Rec(n - 1, x + 1 - 2 * n_th_power_of_2);
}

int main() {
  int n; cin >> n;
  cpp_int x; cin >> x;
  cout << Rec(n, x - 1) << endl;
}
