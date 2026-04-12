/*######################################################
#########~~~~~####~~~~###~~##~~##~~##~~##~~##~~#########
#########~~##~~##~~##~~##~~~#~~##~~~#~~##~~##~~#########
#~~~~~~##~~~~~###~~~~~~##~~#~~~##~~#~~~##~~##~~##~~~~~~#
#########~~######~~##~~##~~##~~##~~##~~##~~##~~#########
#########~~######~~##~~##~~##~~##~~##~~###~~~~##########
######################################################*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#define ll long long
#define str string
#define rtn return
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define db long double
#define MOD 1000000007
#define INF 1e18
#define EPS 1e-15
#define pll pair <ll, ll>
#define vi vector<ll>
#define vpll vector<pll>
#define value_at find_by_order
#define index_of order_of_key
#define fill(a,v) memset(a,v,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(ll i=0;i<n;++i)
#define per(i,n) for(ll i=n-1;i>=0;--i)
#define loop1(i, n) for (int i=1;i<=n;++i)
#define loop(i, begin, end) for (__typeof(end) i = (begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define FAST_IO std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1 << " |";
  __f(comma+1, args...);
}
#else
#define trace(...)
#endif

template<class T> void remin(T &a, T b) {a = min(a, b);}
template<class T> void remax(T &a, T b) {a = max(a, b);}
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define N 3005

ll dp[N][N][2];
ll a[N];
ll n;

ll solve(int i, int j, int mask) {
  if (i == j) {
    if (!mask) rtn a[i];
    else rtn -a[i];
  }
  if (dp[i][j][mask] != -1) rtn dp[i][j][mask];
  if (!mask) {
    dp[i][j][mask] = -INF;
    remax(dp[i][j][mask], a[i] + solve(i + 1, j, !mask));
    remax(dp[i][j][mask], a[j] + solve(i, j - 1, !mask));
  } else {
    dp[i][j][mask] = INF;
    remin(dp[i][j][mask], solve(i + 1, j, !mask) - a[i]);
    remin(dp[i][j][mask], solve(i, j - 1, !mask) - a[j]);
  }
 // trace(i, j, mask, dp[i][j][mask]);
  rtn dp[i][j][mask];
}

int main() {
  FAST_IO;
  fill(dp, -1);
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << solve(0, n-1, 0);
  rtn 0;
}
