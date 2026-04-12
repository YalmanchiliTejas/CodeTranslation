#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  int cost = 1e9;
  for(int i=0; i<=1e5; i++){
    cost = min(cost, i*c+max(0,x-i)*a+max(0,y-i)*b);
  }
  cout << cost << endl;
}
