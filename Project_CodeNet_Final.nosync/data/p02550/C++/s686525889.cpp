// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
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
#define BP(x) __builtin_popcountll(x)
#define PQS priority_queue <int, vector<int>, greater<int> > 
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

const int INF = 1e18 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int N = 1e5 + 5;

int vis[N];
deque <int> v;

int sq(int x) {
  return (x*x);
}

void solve() {
  int n, x, m;
  cin >> n >> x >> m;
  
  vis[x] = 1;
  v.pb(x);
  
  int rem = 0, ans = x, val;
  for(int i = 1; i < n; i++) {
     int y = sq(v[i-1]) % m;
     if(vis[y]) {
       rem = n-i;
       val = y;
       break;
     }
     ans += y;
     v.pb(y);
     vis[y] = y;
  }
  
  if(rem) {
    while(v.front() != val) {
      v.pop_front();
    }
    int si = sz(v);
    int cyc = rem/si;
    int ex = rem%si;
    int sum = 0;
    for(auto i : v) sum += i;

    ans += (cyc * sum);
    for(int i = 0; i < ex; i++) {
      ans += v[i];
    }
  }
  
  cout << ans << '\n';

}

/*
  * overflow, array bounds
  * do smth instead of nothing and stay organized
*/
signed main() {   
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
   int t = 1; // cin >> t;
   for(int i = 1; i <= t; i++) {
   //  cout << "Case #" << i << ": ";
     solve();
  }
}    

/*

*/