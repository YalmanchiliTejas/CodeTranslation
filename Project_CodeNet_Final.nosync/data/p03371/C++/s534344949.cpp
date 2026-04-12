#include <bits/stdc++.h>
using namespace std;

int main() { long A; long B; long C; long X; long Y;
cin >> A >> B >> C >> X >> Y;

// long evenmax = max(X, Y);
// if(max(X, Y) % 2 == 1) evenmax += 1;
long ans = 1e12;
long s;
long t;
// s = A * (X - 5);
long u = 0;

for(long i = 0; i <= max(X, Y) * 2; i += 2){
  s = max(A * (X - i / 2), u);
  t = max(B * (Y - i / 2), u);
  ans = min(C * i + s + t, ans);
}
// ans = max(s, u);

cout << ans << endl;
  return 0;
}