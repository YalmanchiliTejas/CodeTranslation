//Daniel Grzegorzewski
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define int long long

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

const int N = (int)1e5 + 3;

int n, x, m, res, wyn, occ[N], a[N];

signed main() {
  init_ios();
  cin >> n >> a[1] >> m;
  occ[a[1]] = 1;
  res = a[1];
  for (int i = 2; i <= n; ++i) {
    int val = a[i-1]*a[i-1]%m;
    if (occ[val] != 0) {
      res = 0;
      for (int j = 1; j < occ[val]; ++j)
        res += a[j];
      int cyk = 0;
      for (int j = occ[val]; j < i; ++j)
        cyk += a[j];
      int len = n-occ[val]+1;
      int ile = len/(i-occ[val]);
      res += cyk*ile;
      i += (ile-1)*(i-occ[val]);
      int v = val;
      while (i <= n) {
        res += v;
        v = (v*v)%m;
        ++i;
      }
      // cout<<"hm\n";
      cout<<res<<"\n";
      return 0;
    }
    a[i] = val;
    occ[val] = i;
    res += a[i];
  }
  cout<<res<<"\n";
}