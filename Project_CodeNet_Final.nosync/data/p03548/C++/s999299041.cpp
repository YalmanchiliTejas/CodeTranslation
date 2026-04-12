#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

const char nl = '\n' ;
const ll MOD = 1e9 + 7;


int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
   int x, y , z; cin >> x >> y >> z;

   int ans = 0;
   x = x - 2*z;
   while(x >= y)
   {
      ans++;
      x -= y;
      x-=z;
   }
   cout << ans << nl;


}
