#include <bits/stdc++.h>

#define EPS 1e-6
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using namespace std; 

using ll = long long;
using ii = pair<int,int>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, 
    tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ordered_set<ii> S;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (S.empty())
      S.insert(ii(x, i));
    else {
      int p = S.order_of_key(ii(x,-1));
      if (p == 0) {
        S.insert(ii(x,i));
      } else {
        S.erase(S.find_by_order(p - 1));
        S.insert(ii(x,i));
      }
    }
  }

  cout << S.size() << ende;
  return 0;
}
