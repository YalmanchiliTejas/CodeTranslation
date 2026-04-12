#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using ll = long long;

ll height[51], meat[51];

void initialize() {
  height[0] = 1;
  meat[0] = 1;
  for (int i = 1; i <= 50; i++) {
    height[i] = height[i - 1] * 2 + 3;
    meat[i] = meat[i - 1] * 2 + 1;
  }
}

std::pair<ll, ll> eat(int level, ll size) {
  if (size >= height[level])
    return {meat[level], size - height[level]};
  if (size == 0 || size == 1)
    return {0, 0};
  ll meat1, rest1;
  std::tie(meat1, rest1) = eat(level - 1, size - 1);
  if (rest1 == 0)
    return {meat1, 0};
  if (rest1 == 1)
    return {meat1 + 1, 0};
  ll meat2, rest2;
  std::tie(meat2, rest2) = eat(level - 1, rest1 - 1);
  if (rest2 == 0)
    return {meat1 + meat2 + 1, 0};
  std::cerr << "cannot reach here" << std::endl;
  std::exit(1);
  return {-1, 0};
}

int main() {
  initialize();
  int n;
  ll x;
  std::cin >> n >> x;
  std::cout << eat(n, x).first << std::endl;
}
