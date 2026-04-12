#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  int r,g,b,ans; cin >>r >>g >>b;
  if((r*100+g*10+b) % 4 == 0) cout << "YES" << endl;
  else cout <<"NO" <<endl;
  return 0;
}