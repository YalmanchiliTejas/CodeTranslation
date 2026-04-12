#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

ll N, X;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vector<ll> total;
vector<ll> pnum;

ll calc(ll n, ll x) {
  if (n == 0) {
    return (x > 0) ? 1 : 0;
  }
  if (x <= total[n - 1] + 1) {
    return calc(n - 1, x - 1);
  }
  return pnum[n - 1] + 1 + calc(n - 1, x - 2 - total[n - 1]);
}

int main() {
  scanf("%lld %lld", &N, &X);

  total.emplace_back(1);
  pnum.emplace_back(1);
  for (ll i = 1; i <= N; i++) {
    total.emplace_back(total[i - 1] * 2 + 3);
    pnum.emplace_back(pnum[i - 1] * 2 + 1);
  }

  cout << calc(N, X) << endl;
}

// P
// BPPPB
// BBPPPBPBPPPBB
// BBBPPPBPBPPPBBPBBPPPBPBPPPBBB
// BBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBB