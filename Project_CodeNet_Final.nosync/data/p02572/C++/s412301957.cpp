#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long& ai : a) cin >> ai;
  long long ret = 0;
  int mod = 1e9 + 7;

  // for (int i = 0; i < n - 1; ++i) {
  //   for (int j = i + 1; j < n; ++j) {
  //     long long aiaj = a[i] * a[j];
  //     aiaj %= mod;
  //     ret += aiaj;
  //     ret %= mod;
  //   }
  // }

  vector<long long> postfix(n);
  postfix[n - 2] = a[n - 1];
  for (int i = n - 2; i > 0; --i) {
    postfix[i - 1] = a[i] + postfix[i];
    postfix[i - 1] %= mod;
  }

  // for (auto el : postfix) {
  //   cout << el << endl;
  // }
  // cout << endl;

  ret = 0;
  for (int i = 0; i < n; ++i) {
    //
    ret += a[i] * postfix[i];
    ret %= mod;
  }
  cout << ret << endl;
  return 0;
}
