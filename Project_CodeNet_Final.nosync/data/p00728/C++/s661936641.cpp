#include <iostream>
#include <algorithm>

using namespace std;

int nums[10000];

int main() {
  int n;
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) { cin >> nums[i]; }
    sort(nums, nums + n);
    int sum = 0;
    for (int i = 1; i < n - 1; i++) { sum += nums[i]; }
    cout << sum / (n - 2) << endl;
  }
}