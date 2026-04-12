#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }
  int count = 1;
  for (int i = 1; i < N; i++) {
    bool k = true;
    for(int j = 0; j < i; j++) {
      if (h.at(i) < h.at(j)) {
        k = false;
        break;
      }
    }
    if (k) {
      count++;
    }
  }
  cout << count <<endl;
}