#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<bool> s(N);
  char ch;
  for (int i = 0; i < N; ++i) {
    cin >> ch;
    s[i] = (ch == 'o');
  }
  vector<bool> r(N);
  bool find(false);
  for (int i = 0; i < 4; ++i) {
    r[0] = (i / 2 == 0);
    r[1] = (i % 2 == 0);
    for (int j = 2; j < N; ++j) {
      r[j] = (r[j-1] ^ s[j-1]) ? !r[j-2] : r[j-2];
    }
    if ((((r[N-1] ^ s[N-1]) ? !r[N-2] : r[N-2]) == r[0]) && ((r[0] ^ s[0]) ? !r[N-1] : r[N-1]) == r[1]) {
      find = true;
      break;
    }
  }
  if (find) {
    for (int i = 0; i < N; ++i) {
      cout << (r[i] ? 'S' : 'W');
    }
  } else {
    cout << -1;
  }
  cout << endl;
}
