#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long i = 0; i < n; i++)
#define erep(i, n) for(long i = 1; i <= n; i++)

int main(){long X, Y, Z;
cin >> X >> Y >> Z;
long ans = (X - Z) / (Z + Y);


cout << ans << endl;
  return 0;
}