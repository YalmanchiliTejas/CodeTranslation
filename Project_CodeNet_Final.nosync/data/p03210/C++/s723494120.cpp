#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //  repマクロ
#define leng(n) (int)(log10(n)+1)  //  桁数
using namespace std;

signed main() {
  int X;
  cin >> X;
  if (X!=3 && X!=5 && X!=7) cout << "NO" << endl;
  else cout << "YES" << endl;
}