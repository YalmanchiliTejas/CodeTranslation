#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> height(N);
  for (int i = 0; i < N; i++) {
    cin >> height.at(i);
  }
  int watchable;
  for (int i = 0; i < N; i++) {
    bool cansee = true;
    for (int j = 0; j < i; j++) {
      if (height.at(j) > height.at(i)) {
        cansee = false;
      }
    }
    if (cansee) {
      watchable++;
    }
  }
  cout << watchable << endl;
}