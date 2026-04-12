#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MOD 1000000007
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
    // printf("%d\n", n);
  vector<int> nums(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &nums[i]);
    sum += nums[i];
    sum %= MOD;
  }
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    sum -= nums[i];
    // printf("%d\n", nums[i]);
    sum += MOD;
    sum %= MOD;
    result += (long long)sum * (long long)nums[i];
    result %= MOD;
  }

  printf("%lld", result);
  
  return 0;
}