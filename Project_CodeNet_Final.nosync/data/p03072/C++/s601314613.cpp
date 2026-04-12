#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }

  int count = 1;
  int maxh = H.at(0);
  for (int i = 1; i < N; i++) {
    if (H.at(i) >= maxh) {
      count++;
    }
    maxh = max(maxh, H.at(i));
  }
  cout << count << endl;
}
