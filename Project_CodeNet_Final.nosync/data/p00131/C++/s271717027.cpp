#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;

#define PI 3.141592653589793238462643383279
#define mod 1000000007LL
#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define per(i, n) for(i = n - 1;i > -1;--i)
#define int(x) int x; scanf("%d",&x)
#define int2(x, y) int x, y; scanf("%d%d",&x, &y)
#define int3(x, y, z) int x, y, z; scanf("%d%d%d",&x, &y, &z)
#define int4(v, x, y, z) int v, x, y, z; scanf("%d%d%d%d", &v, &x, &y, &z)
#define int5(v, w, x, y, z) int v, w, x, y, z; scanf("%d%d%d%d%d", &v, &w, &x, &y, &z)
#define ll2(x, y) ll x, y; cin >> x >> y;
#define scn(n, a) rep(i, n)cin >> a[i]
#define sc2n(n, a, b) rep(i, n)cin >> a[i] >> b[i]
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define endl "\n"
#define kabe puts("---------------------------")
#define kara puts("")
#define debug(x) cout << " --- " << (x) << "\n"
#define debug2(x, y) cout << " --- " << (x) << " " << (y) << "\n"
#define debug3(x, y, z) cout << " --- " << (x) << " " << (y) << " " << (z) << "\n"
#define X first
#define Y second
#define eps 0.0001
#define prid(x) printf("%.15lf\n", x)

int a[12][12];
int f[12][12];
int res[12][12];
int b[20] = {1};
int dh[5] = {0, 0, 0, 1, -1};
int dw[5] = {0, 1, -1, 0, 0};

signed main(void){
  int i, j, k, l;
  rep1(i, 20)b[i] = b[i - 1] << 1;
  for(int testcase = 0;testcase >= 0;testcase++){
    int(n);
    for(;n--;){
      rep(i, 10)rep(j, 10)scanf("%d", &a[i + 1][j + 1]);
      rep(k, b[10]){
        rep(i, 12)rep(j, 12){
          f[i][j] = a[i][j];
          res[i][j] = 0;
        }
        for(int x = k, d = 1;x;x /= 2){
          res[1][d] = x % 2;
          if(x % 2 == 1)rep(l, 5)f[1 + dh[l]][d + dw[l]] ^= 1;
          ++d;
        }

        rep1(i, 10)rep(j, 10)if(f[i][j + 1] == 1){
          res[i + 1][j + 1] = 1;
          rep(l, 5)f[i + 1 + dh[l]][j + 1 + dw[l]] ^= 1;
        }
        bool isok = true;
        rep(i, 10)rep(j, 10)if(f[i + 1][j + 1] == 1)isok = false;
        if(isok){
          rep(i, 10){
            rep(j, 9)printf("%d ", res[i + 1][j + 1]);
            printf("%d\n", res[i + 1][j + 1]);
          }
          break;
        }
      }
    }


/*/

//*/ break;
  }
  return 0;
}