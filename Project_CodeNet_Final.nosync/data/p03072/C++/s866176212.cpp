#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int h_max = 0;
  int answer = 0;
  for (int i = 0; i < N; i++) {
    int H;
    cin >> H;
    if (H >= h_max) {
      answer++;
      h_max = H;
    }
  }
  cout << answer;

  return 0;
}
