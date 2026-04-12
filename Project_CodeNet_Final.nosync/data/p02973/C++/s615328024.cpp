#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(20);
  
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  deque<int> d;
  rep(i, n) {
    int j = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (j == 0) {
      d.push_front(a[i]);
    } else {
      d[j-1] = a[i];
    }
  }
  cout << d.size() << endl;
  return 0;
}
