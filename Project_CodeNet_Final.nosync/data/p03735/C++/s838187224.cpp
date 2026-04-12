#include <bits/stdc++.h>
using namespace std;
const int N = 200010, INF = (int)1e9;
struct data {
  int x,y;
  bool operator < (const data& a) const {
    return x < a.x;
  }
} dat[N];
typedef long long ll;
int n,bmx = 0,bmn = INF,amx = 0,amn = INF,mx,mn,cur,tmp = INF;
ll ans = 1ll * INF * INF;
int main() {
  scanf("%d",&n);
  for (int i = 1 ; i <= n ; ++ i) {
    scanf("%d%d",&dat[i].x,&dat[i].y);
    if (dat[i].x > dat[i].y) swap(dat[i].x,dat[i].y);
    bmx = max(bmx,dat[i].x);
    bmn = min(bmn,dat[i].x);
    amx = max(amx,dat[i].y);
    amn = min(amn,dat[i].y);
  }
  ans = min(ans,1ll * (bmx - bmn) * (amx - amn));
  mx = amx, mn = bmn, cur = bmx;
  sort(dat+1,dat+n+1);
  for (int i = 1 ; i <= n ; ++ i) {
    ans = min(ans,1ll * (mx - mn) * (cur - min(tmp,dat[i].x)));
    cur = max(cur,dat[i].y);
    tmp = min(tmp,dat[i].y);
  }
  printf("%lld\n",ans);
  return 0;
}