#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <iomanip>
using namespace std;


int main() {
  int n;
  int h[30];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int ans = 0;

  int max_h[30];
  max_h[0] = 0;
  for (int i = 1; i < n; i++) {
    max_h[i] = max(max_h[i-1], h[i-1]);
  }

  for (int i = 0; i < n; i++) {
    if (h[i] >= max_h[i]) {
      ans++;
    }
  }

  cout << ans << endl;
}
