#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i,n) cin >> A[i];
  vector<int> B(n, -1);
  rep(i, n) {
    int a = A[i];
    auto it = lower_bound(B.begin(), B.end(), a);
    --it;
    *it = a;
  }
  int i = 0;
  while (B[i] < 0) ++i;
  int ans = n - i;
  cout << ans << endl;
  return 0;
}