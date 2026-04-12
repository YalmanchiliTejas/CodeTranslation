#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> a;

  rep(i, N) {
    int A; cin >> A;
    auto p = lower_bound(a.rbegin(), a.rend(), A);
    if(p == a.rbegin()) {
      a.push_back(A);
    } else {
      --p;
      *p = A;
    }
  }

  cout << a.size() << endl;
}
