#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

int main(){
  i64 A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  i64 ans = A * X + B * Y;
  ans = min(ans , min(X,Y) * 2 * C + A * (X - min(X,Y)) + B * (Y - min(X,Y)));
  ans = min(ans , max(X,Y) * 2 * C);
  cout << ans << endl;
}
