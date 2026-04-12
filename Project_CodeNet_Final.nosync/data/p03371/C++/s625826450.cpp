#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int z = min(X,Y);
  X -= z; Y -= z;
  int ans = 0;
  
  if (A+B >= 2*C) ans += z*2*C;
  else ans += z*(A+B);
  if (A >= 2*C) ans += X*2*C;
  else ans += X*A;
  if (B >= 2*C) ans += Y*2*C;
  else ans += Y*B;
  
  cout << ans << endl;
}
  