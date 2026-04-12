#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[105] = {0};
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int result = 1;
  int maxH = H[0];
  for (int i = 1; i < N; i++)
  {
    if (maxH <= H[i]) {
      result++;
      maxH = H[i];
    }
  }

  cout << result << "\n";
}