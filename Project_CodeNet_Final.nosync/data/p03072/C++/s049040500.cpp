#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solve(int N, vector<int> H);

void solve(int N, vector<int> H) {
  int ans = 0;
  int hmax = 0;
  for (int h : H) {
    if (h >= hmax) {
      ans += 1;
      hmax = max(hmax, h);
    }
  }
  cout << ans << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  solve(N, H);
  return 0;
}
