#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int> 
#define VPI vector<PII> 
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())
const int inf = 1e9 + 7;
const int M = 200005;

int n;
PLL T[M];
LL mini = inf, maxi, rmini = inf, lmaxi;
LL res;
vector<PLL> V;
set<PLL> secik;

int main()
{
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    LL x, y;
    scanf("%lld%lld", &x, &y);
    if (x > y)
    {
      swap(x, y);
    }
    mini = min(mini, x);
    maxi = max(maxi, y);
    rmini = min(rmini, y);
    lmaxi =max(lmaxi, x);
    V.PB(MP(x, i));
    T[i] = MP(x, y);
    secik.insert(MP(-x, i));
  }
  //debug("%d %d %d %d\n", mini, maxi, lmaxi, rmini);
  sort(ALL(V));
  res = (lmaxi - mini) * (maxi - rmini);
 // printf("%lld\n", res);
  LL red = maxi - mini;
  PLL blue = MP(min(rmini, lmaxi), max(rmini, lmaxi));
  for (int i = 0; i < n; i++)
  {
    LL rig = blue.S;
    if (!secik.empty())
    {
      rig = max(rig, -secik.begin()->F);
    }
    LL blue2 = rig - min(blue.F, V[i].F);
    res = min(res, red * blue2);
    blue.S = max(blue.S, T[V[i].S].S);
    secik.erase(MP(-T[V[i].S].F, V[i].S));
  }
  printf("%lld\n", res);
  return 0;
}