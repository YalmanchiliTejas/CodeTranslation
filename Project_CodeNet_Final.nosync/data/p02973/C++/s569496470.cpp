#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << setiosflags(ios::fixed);

  int n, a;
  cin >> n;
  multiset<int> q;
  rep(i,n){
    cin >> a;
    auto it = q.upper_bound(a - 1);
    if (it != q.begin())
      q.erase(--it);
    q.insert(a);
  }
  cout << q.size() << '\n';
}