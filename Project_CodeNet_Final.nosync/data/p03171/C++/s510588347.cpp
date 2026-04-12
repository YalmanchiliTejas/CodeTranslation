// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>

const int INF = 1e15 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int N = 5e3 + 5;
int dp[N][N], n, Data[N];

int go(int l, int r) {
  if(l > r) return 0;
  int &x = dp[l][r];
  if(x != -INF) return x;
  if((r-l+1)%2 == n%2) {
    x = max(Data[l]+go(l+1, r), Data[r]+go(l, r-1));
  }
  else {
    x = min(-Data[l]+go(l+1, r), -Data[r]+go(l, r-1));
  }
  return x;
}

void solve() {
  for(int i = 1; i < N; i++) for(int j = 1; j < N; j++) dp[i][j] = -INF;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> Data[i];
  cout << go(1, n) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int t = 1; // cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}    
