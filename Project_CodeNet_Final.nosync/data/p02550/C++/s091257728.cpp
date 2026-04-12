#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

#define int long long
#define mod 1000000007
#define pb push_back
#define S second
#define F first
#define INF 1e18
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n" \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, m;
  cin >> n >> x >> m;

  int ans = 0;
  vector<int> prev;
  map<int,bool> seen;
  int cur = 1,start = -1;
  while(cur <= n) {
    if(seen.find(x) != seen.end()) {
      break;  
    } 
    ans = (ans + x);
    prev.pb(x);
    seen[x] = 1;
    x = (x % m * x % m) % m;
    cur++;
  }

  if(cur >= n) {
    cout << ans;
    return 0;
  }

  int val = 0,  ok = -1;
  for(int i = 0; i < prev.size(); ++i) {
    if(prev[i] == x && ok == -1)
      ok = i;
    if(ok != -1)
      val = val + prev[i];
  }
  int len = prev.size() - ok ;

 // while(len + cur <= n) {
 //   ans = (ans + val);
 //   cur += len;
 // }
 
  int maxm = (n - cur) / len;
  cur += maxm * len;
  ans += val * maxm;

  for(;cur<=n;cur++) {
    ans = (ans + prev[ok]);
    ok++;
  }
  cout << ans;
}
