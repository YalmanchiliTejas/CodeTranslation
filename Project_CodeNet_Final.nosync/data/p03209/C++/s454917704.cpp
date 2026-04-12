#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> h(60, 0), b(60, 0);
ll func(ll n, ll x) {
  if(n == 0) {
    if(x <= 0) {
      return 0;
    } else {
      return 1;
    }
  } else if(x <= h[n - 1] + 1) {
    return func(n - 1, x - 1);
  } else {
    return h[n - 1] - b[n - 1] + 1 + func(n - 1, x - h[n - 1] - 2);
  }
}

int main() {
  ll n, x;
  cin >> n >> x;
  h[0] = 1;
  for(int i = 0; i < n; i++) {
    b[i + 1] = b[i] * 2;
    h[i + 1] = h[i] * 2;
    h[i + 1] += 3;
    b[i + 1] += 2;
  }
  cout << func(n, x) << endl;
  return 0;
}