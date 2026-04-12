#include <bits/stdc++.h>
using namespace std;

int main() {
  int	N, H, h=0, i, s;
  // string	S;
  // int	i, j, l, ll;
  // char b;
  //  int N, K, KK, x, s=0;
  cin >> N >> h;
  for (s = i = 1; i < N; i++) {
    cin >> H;
    if (H >= h ) {
      s++;
      h = H;
    }
  }
  cout << s << endl;
  return 0;
}
