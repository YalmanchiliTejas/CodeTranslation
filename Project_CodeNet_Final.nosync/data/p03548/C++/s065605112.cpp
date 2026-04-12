#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int ans = (X - Z) / (Z + Y);
  cout << ans << endl;
}
