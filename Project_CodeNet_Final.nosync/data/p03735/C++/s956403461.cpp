#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5, inf = 2e9;

ii a[maxn];
ll res = 1e18;
int N;
int Min = inf, Max;
multiset<int> ms;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if(fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  cin >> N;
  for(int i = 1; i <= N; ++i){
    cin >> a[i].fi >> a[i].se;
    if(a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    Min = min(Min, a[i].fi);
    Max = max(Max, a[i].se);
    ms.insert(a[i].fi);
  }
  int mi = inf, ma = 0;
  for(int i = 1; i <= N; ++i){
    ma = max(ma, a[i].fi);
    mi = min(mi, a[i].se);
  }
  res = 1ll * (ma - Min) * (Max - mi);
  sort(a + 1, a + 1 + N);
  res = min(res, 1ll * (*ms.rbegin() - *ms.begin()) * (Max - Min));
  for(int i = 1; i <= N; ++i){
    ms.erase(ms.find(a[i].fi));
    ms.insert(a[i].se);
    res = min(res, 1ll * (*ms.rbegin() - *ms.begin()) * (Max - Min));
  }
  cout << res;
}
