#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const N = 100*1000 + 16;
int const M = 1000*1000*1000 + 7;

int n;
ll a[64];
ll b[64];

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a+n);
  ll sum = 0;

  for(int k = 0; k < 100000; ++k) {
    ll z = 0;
    for(int i = 0; i < n; ++i) {
      if(a[i] < n)
        continue;
      auto x = a[i] - n;
      b[i] = x/n;
      z += b[i];
    }

    for(int i = 0; i < n; ++i)
      a[i] = a[i] - n * b[i] + (z - b[i]);
    sum += z;
  }


  multiset<ll, greater<ll>> s;
  for(int i = 0; i < n; ++i) {
    auto x = a[i];
    s.insert(x);
  }

  ll d = 0;
  while(*s.begin()+d >= n) {
    auto x = *s.begin();
    s.erase(s.begin());
    s.insert(x-(n+1));
    ++d;
    ++sum;
  }

  cout << sum;
}