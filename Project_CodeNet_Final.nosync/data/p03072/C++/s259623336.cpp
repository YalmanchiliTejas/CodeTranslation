#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++) {
    cin >> H.at(i);
  }
  int answer = 1;
  bool view;
  for (int i=1; i<N; i++) {
    for (int j=0; j<i; j++) {
      if (H.at(j)>H.at(i)) {
        view = false;
        break;
      }
      view = true;
    }
    if (view) {
      answer++;
    }
  }
  cout << answer << endl;
}