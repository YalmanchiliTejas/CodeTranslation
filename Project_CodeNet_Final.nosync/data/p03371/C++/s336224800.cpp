#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define fi first
#define se second
using ll= long long;
using namespace std;
using pii = pair<int,int>;

int a, b, c;
int X, Y;

int main()
{
   cin.tie(0), ios::sync_with_stdio(false);

   cin >> a >> b >> c >> X >> Y;

   int c2 = c*2;
   int minv = min(X, Y);

   int x_cost = min(c2, a);
   int y_cost = min(c2, b);

   ll ans = (ll)X * x_cost + (ll)Y * y_cost;

   {
      ll tmp = c2 * X;
      if (Y > X) {
         tmp += y_cost * (Y-X);
      }
      ans = min(ans, tmp);
   }

   {
      ll tmp = c2 * Y;
      if (X > Y) {
         tmp += x_cost * (X-Y);
      }
      ans = min(ans ,tmp);
   }

   outl(ans);

}

