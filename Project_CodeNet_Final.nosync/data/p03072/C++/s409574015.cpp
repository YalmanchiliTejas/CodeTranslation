#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;

  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }

  int sum = 1;
  for (int i = 1; i < N; i++) {
    bool flg = true;
    for (int j = 0; j < i && flg; j++) {
      if (v.at(j) > v.at(i)) flg = false;
    }
    if (flg) sum++;
  }

  cout << sum << endl;
}
/*
  4
  6 5 6 8
 */

 
