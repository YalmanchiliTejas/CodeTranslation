#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  int count = 0;
  for (int i = 1; i < N; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (H.at(i) - H.at(j) < 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      count++;
    }
  }
  cout << count + 1 << endl;
}
