#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  // 昇順に入れる
  vector<ll> a;
  rep(i, n-1) {
    if (i % 2 == 0) {
      a.push_back(v[i/2]);
    } else {
      a.push_back(v[n-((i-1)/2)-1]);
    }
  }
  if (abs(a[0] - v[n/2]) < abs(a[n-2] - v[n/2])) {
    a.push_back(v[n/2]);
  } else {
    a.insert(a.begin(), v[n/2]);
  }
  // 降順に入れる
  sort(v.begin(), v.end(), greater<ll>());
  vector<int> b;
  rep(i, n-1) {
    if (i % 2 == 0) {
      b.push_back(v[i/2]);
    } else {
      b.push_back(v[n-((i-1)/2)-1]);
    }
  }
  if (abs(b[0] - v[n/2]) < abs(b[n-2] - v[n/2])) {
    b.push_back(v[n/2]);
  } else {
    b.insert(b.begin(), v[n/2]);
  }
  ll pa = a[0];
  ll pb = b[0];
  ll ca = 0;
  ll cb = 0;
  for(int i = 1; i < n; i++) {
    ca += abs(a[i] - pa);
    cb += abs(b[i] - pb);
    pa = a[i];
    pb = b[i];
  }
  cout << max(ca, cb);
}
