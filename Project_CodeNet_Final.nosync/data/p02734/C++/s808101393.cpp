// Daniel Grzegorzewski
// while (clock()<=69*CLOCKS_PER_SEC)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

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

//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczbę elementów ostro mniejszych niż k

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

const int N = 3005;
const int MOD = 998244353;

int n, s, res, a[N], zacz[N], kon[N], cnt1[2][N], cnt2[2][N], wtf[N];

void calc(int l, int r) {
  if (l > r)
    return;
  if (l == r) {
    if (a[l] == s)
      res = (res+(n+1-r)*r)%MOD;
    return;
  }
  int mid = (l+r)/2;
  calc(l, mid);
  calc(mid+1, r);
  for (int i = 0; i <= s; ++i)
    cnt1[0][i] = cnt1[1][i] = cnt2[0][i] = cnt2[1][i] = 0;
  cnt2[0][0] = 1;
  for (int i = 0; i <= s; ++i)
    wtf[i] = 0;
  for (int i = mid+1; i <= r; ++i) {
    for (int j = 0; j <= s; ++j)
      cnt2[1][j] = cnt2[0][j];
    for (int j = s; j-a[i] >= 0; --j)
      cnt2[1][j] = (cnt2[1][j]+cnt2[0][j-a[i]])%MOD;
    for (int j = 1; j < s; ++j) {
      int ile = ((cnt2[1][j]-cnt2[0][j])%MOD+MOD)%MOD;
      wtf[j] = (wtf[j]+ile*(n+1-i))%MOD;
    }
    for (int j = 0; j <= s; ++j)
      cnt2[0][j] = cnt2[1][j];
  }
  cnt1[0][0] = 1;
  for (int i = mid; i >= l; --i) {
    for (int j = 0; j <= s; ++j)
      cnt1[1][j] = cnt1[0][j];
    for (int j = s; j-a[i] >= 0; --j)
      cnt1[1][j] = (cnt1[1][j]+cnt1[0][j-a[i]])%MOD;
    for (int ls = 1; ls < s; ++ls) {
      int ile = ((cnt1[1][ls]-cnt1[0][ls])%MOD+MOD)%MOD;
      ile = (ile*(i+1-1))%MOD;
      res = (res+ile*wtf[s-ls])%MOD;
    }
    for (int j = 0; j <= s; ++j)
      cnt1[0][j] = cnt1[1][j];
  }
}

signed main() {
  init_ios();
  cin >> n >> s;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  calc(1, n);
  cout<<res<<"\n";
}