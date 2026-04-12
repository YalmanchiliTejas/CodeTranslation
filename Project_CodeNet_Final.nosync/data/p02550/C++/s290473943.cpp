#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N, X, M;
  scanf("%lld %lld %lld", &N, &X, &M);

  ll x = X;

  mll m;

  vll list;
  list.emplace_back(-1);

  ll i = 1;
  ll start;
  ll cycle;
  for (;;) {
    list.emplace_back(x);
    if (m[x]) {
      start = m[x];
      cycle = i - m[x];
      break;
    }
    m[x] = i;

    x = x * x % M;
    i++;
  }

  ll sum = 0;
  x = X;

  for (ll i = 1; i <= cycle; i++) {
    sum += list[i + start];
  }

  ll ans = 0;
  ll n = N;
  for (int i = 1; i < start; i++) {
    n -= 1;
    ans += list[i];
    if (n <= 0) {
      break;
    }
  }

  ll loops = n / cycle;
  ans += (sum * loops);

  n = n % cycle;

  if (n > 0) {
    for (int i = start;; i++) {
      n -= 1;
      ans += list[i];
      if (n <= 0) {
        break;
      }
    }
  }

  cout << (ans) << endl;
}
