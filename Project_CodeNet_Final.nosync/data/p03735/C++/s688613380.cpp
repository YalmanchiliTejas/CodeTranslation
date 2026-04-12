#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 200005;

int MX[N],MN[N];
vector<pii> v;
set<pii > mx,mn;

int main() {
  int n;
  S(n);

  rep(i,0,n) {
    int x,y;
    S2(x,y);
    MX[i] = max(x,y);
    MN[i] = min(x,y);
    v.pb(mp(MN[i],MX[i]));
  }
  sort(all(v));
  rep(i,0,n) {
    mn.insert(mp(v[i].FF,i));
    mx.insert(mp(v[i].SS,i));
  }
  LL ans = ((*mx.rbegin()).FF - (*mx.begin()).FF) * 1LL * ((*mn.rbegin()).FF - (*mn.begin()).FF);
  rep(i,0,n) {
    pii p = *mn.begin();
    mx.erase(mp(v[p.SS].SS,p.SS));
    mx.insert(mp(v[p.SS].FF,p.SS));

    mn.erase(mp(v[p.SS].FF,p.SS));
    mn.insert(mp(v[p.SS].SS,p.SS));
  
    LL val = ((*mx.rbegin()).FF - (*mx.begin()).FF) * 1LL * ((*mn.rbegin()).FF - (*mn.begin()).FF);
    ans = min(ans, val);
  }
  cout << ans << "\n";
  return 0;
}
