#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int64 i = 0; i < (int64)(n); i++)

using int64 = long long;
const int64 INF = 1LL << 60;

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ret = 0;
  for(int i = Z; i <= X; i += Z) {
    if(i + Y + Z > X) break;
    ++ret;
    i += Y;
  }

  cout << ret << endl;
}
