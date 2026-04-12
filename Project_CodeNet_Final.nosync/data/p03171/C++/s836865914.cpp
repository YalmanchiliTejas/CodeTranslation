#include <cstring>
#include <cassert>
#include <utility>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <tuple>
#include <climits>
#include <limits>
#include <deque>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll              long long
#define pi              pair<int,int>
#define pll             pair<ll,ll>
#define pb              push_back
#define F               first
#define S               second
#define vi              vector<int>
#define vll             vector<ll>
#define endl            '\n'
#define all(v)          (v).begin(),(v).end()
#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define MP(a,b)         make_pair(a,b)
#define debug(x)        cerr<< #x << " : " << x << endl;
#define debugp(p)       cerr<< #p << " : " << "(" << (p).first << "," << (p).second << ")\n";
#define debugv(v)       cerr<< #v << " : " << "["; for(int i = 0; i < (v).size(); i++) cerr << v[i] << " "; cerr<<"]\n";
#define debugs(m)       cerr<< #m << " : [ "; for(auto itr = m.begin(); itr != m.end(); itr++) cerr <<*itr << " "; cerr << "]\n";
#define debugm(m)       cerr<< #m << " : [ "; for(auto itr = m.begin(); itr != m.end(); itr++) cerr <<"(" << itr->first << "," << itr->second << ") "; cerr << "]\n";

/* ordered set: 
tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
member functions :
1. order_of_key(k) : number of elements strictly lesser than k
2. find_by_order(k) : k-th element in the set
*/

inline ll modexp(ll x, ll ex , ll md) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % md;
        ex >>= 1ll;
        x = (x * x) % md;
    }
    return ans;
}

const ll inf = 1e18 + 7;

void solve(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<long long>> dp (n + 1 , vector<long long> (n + 1 , -inf));
  for (int i = n - 1; i >= 0; i--){
    for (int j = i; j < n; j++){
      if (i == j) dp[i][j] = a[i];
      else{
        assert (j >= i + 1);
        dp[i][j] = max (dp[i][j] , a[i] - dp[i + 1][j]);
        dp[i][j] = max (dp[i][j] , a[j] - dp[i][j - 1]);
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}
int main(){
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    #ifdef LOCAL
    cerr << "Time elapsed\t: " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";       
    #endif
}

