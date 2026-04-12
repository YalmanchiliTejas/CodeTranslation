#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 200005
#define modulo 1000000007L

int nums[MAX_SIZE], right_sums[MAX_SIZE];

int main() {
  int n_nums = 0;
  scanf("%d", &n_nums);
  memset(nums, 0, sizeof(nums));
  memset(right_sums, 0, sizeof(right_sums));

  for (int i = 0; i < n_nums; ++i) {
    scanf("%d", nums+i);
  }

  // reverse sum
  for (int i = n_nums-1; i >= 0; --i) {
    right_sums[i] = (right_sums[i+1] + nums[i]) % modulo;
  }


  long long ans = 0;
  for (int i = 0; i < n_nums-1; ++i) {
    ans = (ans + (long long)(right_sums[i+1]) * (long long)nums[i]) % modulo;
  }
  printf("%d\n", int(ans));
  return 0;
}