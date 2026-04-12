#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long ma = -1, res = 0;
  for (int i = 0; i < N; ++i) {
    long long h; 
    cin >> h;
    if (h >= ma) ++res;
    ma = max(ma, h);
  }
  cout << res << endl;
}