#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
   int a,b,c,x,y;
   cin >> a >> b >> c >> x >> y;
   int ans = 0;
   if(a+b>c*2)
   {
      int poiu = min(x,y);
      x -= poiu;
      y -= poiu;
      ans += c*poiu*2;
   }
   if(a>c*2)
   {
      int poiu = x;
      ans += x *c * 2;
      x = 0;
   }
   if(b>c*2)
   {
      ans += y*c*2;
      y = 0;
   }
   ans += x*a;
   ans += y*b;

cout<<ans<<endl;
   return 0;
}