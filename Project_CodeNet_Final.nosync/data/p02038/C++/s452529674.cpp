#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<char> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
  int ans = true;
  for (int i = 0; i < N; i++) {
    ans = !(ans && P[i] == 'F');
  }
  cout << ( (ans) ? 'T' : 'F' ) << endl;
}

