#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int cnt1, cnt2;
  map<ll, ll> cnts1_map, cnts2_map;
  for (int i = 0; i < n; ++i) {
    int amount = i == 0 || i == n - 1 ? 1 : 2;
    int sign = i % 2 == 0 ? -1 : 1;
    cnts1_map[amount * sign]++;
    cnts2_map[amount * -sign]++;
  }

  sort(va.begin(), va.end());

  ll ans1 = 0, ans2 = 0, cur = 0;
  for (auto &p : cnts1_map) {
    ans1 += p.first *
            accumulate(va.begin() + cur, va.begin() + cur + p.second, 0ll);
    cur += p.second;
  }

  cur = 0;
  for (auto &p : cnts2_map) {
    ans2 += p.first *
            accumulate(va.begin() + cur, va.begin() + cur + p.second, 0ll);
    cur += p.second;
  }

  cout << max(ans1, ans2) << '\n';
}