#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
 
ll num[55];
ll paty[55];
 

ll f(int level, ll x) {
  if(level == 0) {
    return x > 0 ? 1 : 0;
  }
  ll ret = 0;
  if(x >= num[level-1] + 2) {
    return paty[level-1] + 1 + f(level-1, x-num[level-1]-2);
  } else {
    return  f(level-1, x-1);
  }
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, X;
  cin >> N >> X;
  num[0] = 1;
  paty[0] = 1;
  FOR(i,1,55) {
    num[i] = 2 * num[i - 1] + 3;
    paty[i] = 2 * paty[i - 1] + 1;
  }
  cout << f(N, X) << endl;
}