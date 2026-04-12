#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define _debug(fmt, ...) fprintf(stderr, "%s: " fmt "\n", __func__, ##__VA_ARGS__)
#define rep(i, n) for (int i=0; i<(n); i++)
#define Rep(i, n) for (int i=1; i<=(n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;

tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> rkt;

int n;
int a[200005];

int main() {
  cin >> n;
  rep (i, n) {
    cin >> a[i];
    rkt.insert({a[i], i});
  }
  rep (i, n) {
    rkt.erase({a[i], i});
    cout << rkt.find_by_order(n/2-1)->first << endl;
    rkt.insert({a[i], i});
  }

  return 0;
}

