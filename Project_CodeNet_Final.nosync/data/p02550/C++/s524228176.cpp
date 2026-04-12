#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
const int N = 2e3+ 2, mod = 998244353;


void solve() {
     ll n, x, m;
     cin >> n >> x >> m;
     vector<int> cnt(m);
     ll ans = 0;
     vector<int> b;
     ll l = 0;
     for(int i = 0; i < n; i++) {
          if(cnt[x] != 0) {
               break;
          } else {
               b.push_back(x);
               cnt[x]++;
          }
          ans += x;
          // cout << x << ' ';
          l++;
          x = (x*x)%m;
     }
     // ans += x;
     // cout << x << '\n';
     ll sz = b.size();
     vector<ll> a;
     ll s = 0;
     int id = sz;
     for(int i = 0; i < sz; i++) {
          if(b[i] == x) {
               id = i;
               break;
          }
     }
     for(int i = id; i < sz; i++) {
          s += b[i];
          // cout << s << " ";
          a.push_back(s);
     }
     sz = a.size();
     if(!sz) {
          cout << ans << '\n';
          return;
     }
     n -= l;
     ans += (n/sz)*s;
     int y = (n % sz) - 1;
     if(y >= 0) {
          ans += a[y];
     }
     cout << ans << '\n';
}    


int main() {
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout << "Case #:" << tc << " ";
		solve();
	}
}