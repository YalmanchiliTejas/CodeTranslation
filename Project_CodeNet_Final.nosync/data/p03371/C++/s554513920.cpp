#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 1e9;
  for(int i=0; i<max(X, Y)*2; i++){
    int ab = i*2;
    int a = max(0, X-i);
    int b = max(0, Y-i);
    ans = min(a*A+b*B+ab*C, ans);
  }

  cout << ans << endl;
}
