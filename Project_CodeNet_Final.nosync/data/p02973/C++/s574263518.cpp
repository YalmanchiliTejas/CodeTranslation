#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a, now;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  for(int i = 0; i < n; ++i) {
    auto it = upper_bound(now.begin(), now.end(), a[i],
                          greater<long long>());
    if(it == now.end())
      now.push_back(a[i]);
    else
      *(it) = a[i];
  }
  return now.size();
}