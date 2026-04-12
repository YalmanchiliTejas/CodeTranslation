#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;

ll k, a, b;
ll solve()
{

  if (a >= k)
    return 1;
  else if (a <= b)
    {
      return -1ll;
    }
  else
    {
      ll dif = a-b;;
      k -= a;
      return 1ll+2*((k+dif-1)/dif);
    }
}
int main()
{
  scanf("%lld %lld %lld", &k, &a, &b);
  printf("%lld\n", solve());
}
