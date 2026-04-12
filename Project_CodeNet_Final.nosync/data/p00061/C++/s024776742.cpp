#include<iostream>
#include<sstream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cfloat>
#include<functional>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<bitset>
#include<list>
#include<numeric>
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<long long, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<long long, long long> ll_ll;
typedef pair<double, double> d_d;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define rep2d(i, j, n) for(i = 0;i < n;++i)for(j = i + 1;j < n;++j)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define sc(x) cin >> x
#define sc2(x, y) cin >> x >> y
#define sc3(x, y, z) cin >> x >> y >> z
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << x << "\n"
#define pri2(x, y) cout << x << " " << y << "\n"
#define pri3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << x << "\n"
#define debug2(x, y) cout << " --- " << x << " " << y << "\n"
#define debug3(x, y, z) cout << " --- " << x << " " << y << " " << z << "\n"
#define debugn(i, n, a) rep(i, n)cout << " --- " << a[i] << "\n";
#define debugin(i, n, a) rep(i, n)printf(" --- %10d\n", a[i])
#define debugi2n(i, n, a, b) rep(i, n)printf(" --- %10d %10d\n", a[i], b[i])
#define debugiin(i, n, a) rep(i, n)printf(" --- %10d %10d\n", a[i].first, a[i].second)
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

bool mycom(i_i a, i_i b){
  return a.Y > b.Y;
}

signed main(void){
  int i, j;
  for(int testcase = 0;;testcase++){
    vector<i_i> lis;
    for(;;){
      int a, b;
      scanf("%d,%d", &a, &b);
      if(a == 0 && b == 0)break;
      lis.pb(mp(a, b));
    }

    sort(all(lis), mycom);

    for(int x;scanf("%d", &x) != EOF;){
      int cnt = 1;
      for(i = 0;;){
        if(lis[i].X == x)break;
        ++i;
        if(i >= lis.size())break;
        if(lis[i - 1].Y != lis[i].Y)cnt++;
      }
      pri(cnt);
    }


/*/

//*/ break;
  }
  return 0;
}