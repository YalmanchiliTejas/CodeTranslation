#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
    cin >> a.at(i);

  long long sum = 0;
  long long u = 0;
  for (int i = n - 1; i > 0; i--) {
    u += a.at(i);
    u = u % 1000000007;
    sum += u * a.at(i - 1);
    sum = sum % 1000000007;
  }

  cout << sum << endl;

  return 0;
}