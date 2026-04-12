#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<int> height(n, 0);
  vector<int> maxh(n, 0);
  for(int i = 0; i < n; ++i) {
    cin >> height[i];
    if(i == 0) {
      maxh[i] = height[i];
    } else {
      maxh[i] = max(maxh[i - 1], height[i]);
    }
  }
  int result = 0;
  for(int i = 0; i < n; ++i) {
    if(maxh[i] <= height[i]) {
      result += 1;
    }
  }
  cout << result << endl;
  return 0;
}