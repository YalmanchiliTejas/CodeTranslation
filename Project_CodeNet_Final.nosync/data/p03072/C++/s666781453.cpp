#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

int main() {
  int N;
  cin >> N;

  vector<int> h(N);
  int count = 0;
  int maxH = 0;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
    if (h[i] >= maxH) {
      count++;
      maxH = h[i];
    }
  }

  cout << count << endl;

  return 0;
}
