#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  long long n, p = 0, l = 0;
  cin >> n;
  vector<int> a(n);
  for (long long i=0; i<n; i++) {
    cin >> a[i];
    p += a[i];
  }
  for (long long i=0; i<n-1; i++) {
    p -= a[i];
    l += (a[i]%1000000007)*(p%1000000007);
    l %= 1000000007;
  }
  cout << l << endl;
}