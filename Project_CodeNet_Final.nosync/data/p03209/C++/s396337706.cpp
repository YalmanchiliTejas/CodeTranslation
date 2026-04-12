#include <iostream>
#include <vector>
using namespace std;
vector<long long> nums(60);
long long memo[60];
long long rec(int layer, long long index) {
  if (layer == 0) return 1;
  if (index == nums[layer] && memo[layer]) {
    return memo[layer];
  }
  long long num = nums[layer - 1];
  long long ret = 0;
  if (index <= 1) return 0;
  if (index <= num + 1) {
    return 0 + rec(layer - 1, index - 1);
  }
  if (index == num + 2) {
    return 0 + (memo[layer - 1] = rec(layer - 1, num)) + 1;
  }
  return 0 + (memo[layer - 1] = rec(layer - 1, num)) + 1 + rec(layer - 1, min(index - num - 2, num));
}
int main() {
  nums[0] = 1;
  for (int i = 0; i <= 49; i++) {
    nums[i + 1] = nums[i] * 2 + 3;
  }
  int n;
  long long x;
  cin >> n >> x;
  cout << rec(n, x) << endl;
  return 0;
}