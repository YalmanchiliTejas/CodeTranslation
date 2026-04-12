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
#define int unsigned long long

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

const int N = 503;

int n, s[N], t[N], u[N], v[N], a[N][N];

signed main() {
  init_ios();
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> s[i];
  for (int i = 1; i <= n; ++i)
    cin >> t[i];
  for (int i = 1; i <= n; ++i)
    cin >> u[i];
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 0) {
      for (int j = 1; j <= n; ++j)
        a[i][j] |= u[i];
    }
  }
  for (int j = 1; j <= n; ++j)
    if (t[j] == 0) {
      for (int i = 1; i <= n; ++i)
        a[i][j] |= v[j];
    }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 1) {
      set<int> bity;
      for (int j = 0; j < 64; ++j)
        if (u[i]&(1LL<<j))
          bity.insert(j);
      for (int j = 1; j <= n; ++j) {
        if (a[i][j])
          for (int k = 0; k < 64; ++k)
            if (a[i][j]&(1LL<<k))
              bity.erase(k);
      }
      for (int j = 1; j <= n; ++j) {
        if (t[j] == 1) {
          VI uzyte;
          for (int x: bity)
            if (v[j]&(1LL<<x)) {
              uzyte.PB(x);
              a[i][j] |= (1LL<<x);
            }
          for (int x: uzyte)
            bity.erase(x);
        }
      }
      for (int x: bity) {
        for (int j = 1; j <= n; ++j) {
          if (t[j] == 0) {
            int cnt = 0;
            for (int k = 1; k <= n; ++k) {
              if (!(a[k][j]&(1LL<<x)))
                ++cnt;
            }
            if (cnt > 1) {
              a[i][j] ^= (1LL<<x);
              break;
            }
          }
        }
      }
    }
  }
  for (int j = 1; j <= n; ++j)
    if (t[j] == 1) {
      set<int> bity;
      for (int k = 0; k < 64; ++k)
        if (v[j]&(1LL<<k))
          bity.insert(k);
      for (int i = 1; i <= n; ++i) {
        if (a[i][j]) {
          for (int k = 0; k < 64; ++k)
            if (a[i][j]&(1LL<<k))
              bity.erase(k);
        }
      }
      for (int x: bity) {
        for (int i = 1; i <= n; ++i) {
          if (s[i] == 0) {
            int cnt = 0;
            for (int k = 1; k <= n; ++k) {
              if (!(a[i][k]&(1LL<<x)))
                ++cnt;
            }
            if (cnt > 1) {
              a[i][j] |= (1LL<<x);
              break;
            }
          }
          else if (u[i]&(1LL<<x)) {
            a[i][j] |= (1LL<<x);
            break;
          }
        }
      }
    }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 0) {
      int cur = a[i][1];
      for (int j = 2; j <= n; ++j)
        cur &= a[i][j];
      if (cur != u[i]) {
        cout<<"-1\n";
        return 0;
      }
    }
    else {
      int cur = a[i][1];
      for (int j = 2; j <= n; ++j)
        cur |= a[i][j];
      if (cur != u[i]) {
        cout<<"-1\n";
        return 0;
      }
    }
  }
  for (int j = 1; j <= n; ++j) {
    if (t[j] == 0) {
      int cur = a[1][j];
      for (int i = 1; i <= n; ++i)
        cur &= a[i][j];
      if (cur != v[j]) {
        cout<<"-1\n";
        return 0;
      }
    }
    else {
      int cur = a[1][j];
      for (int i = 1; i <= n; ++i)
        cur |= a[i][j];
      if (cur != v[j]) {
        cout<<"-1\n";
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      cout<<a[i][j]<<" ";
    cout<<"\n";
  }
}