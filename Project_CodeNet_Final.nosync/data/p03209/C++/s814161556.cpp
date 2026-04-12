#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void calc_burger(int x, ll *height, ll *patty) {
  if (x == 0) {
    height[x] = 1;
    patty[x] = 1;
    return;
  }
  calc_burger(x - 1, height, patty);
  height[x] = 3 + height[x - 1] * 2;
  patty[x] = 1 + patty[x - 1] * 2;
}

ll calc_patty(ll x, int layer, ll *height, ll *patty) {
  if (x >= height[layer]) return patty[layer];
  if (x <= 1) return 0;

  ll num = 0;
  num += calc_patty(x - 1, layer - 1, height, patty);
  if (x > 1 + height[layer - 1]) num++;
  num += calc_patty(x - 2 - height[layer - 1], layer - 1, height, patty);

  return num;
}

int main() {
  ll n, x;
  cin >> n >> x;

  ll height[51] = {}, patty[51] = {};

  calc_burger(n, height, patty);
  cout << calc_patty(x, n, height, patty) << endl;
  return 0;
}