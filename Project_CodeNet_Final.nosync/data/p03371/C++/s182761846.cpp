#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int a,b,ab;
  cin >> a >> b >> ab;
  
  int x,y;
  cin >> x >> y;
  
  ll ans = x*a + y*b;
  if(ab*max(x,y)*2 < ans)
  {
    ans = ab * max(x,y) * 2;
  }
  
  if(ab*min(x,y)*2 + a*(x-min(x,y)) + b*(y-min(x,y)) < ans)
  {
    ans = ab * min(x,y) * 2 + a*(x-min(x,y)) + b*(y-min(x,y));
  }
  
  
  cout << ans << endl;
}