#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, now=-1, count=0;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++) cin >> H.at(i);
  for (int i=0; i<N; i++) {
    if (H.at(i) >= now) {
      count++;
      now = H.at(i);
    }
  }
  cout << count << endl;
}
