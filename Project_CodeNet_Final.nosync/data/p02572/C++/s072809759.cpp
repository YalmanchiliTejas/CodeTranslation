#include <bits/stdc++.h>
using namespace std;
long long x (long long n, long long m) {
  long long N;
  if((n - m) >= 0) N = n - m;
  else N = 1000000007 + n - m;
  return N;
}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  long long s = 0;
  for(int i = 0; i < n; i++) {
    s += a.at(i);
    s = s % 1000000007;
  }
  long long ans = 0;
  for(int i = 0; i < (n - 1); i++) {
    s = x(s, a.at(i));
    long long p = s * a.at(i);
    ans += p;
    ans = ans % 1000000007;
  }
  cout << ans << endl;
}