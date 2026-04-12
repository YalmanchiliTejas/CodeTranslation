#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
//#pragma GCC optimize("Ofast")
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
#define int ll
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define floatprec(dig) fixed << setprecision(dig)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define invar(typ, var) typ var; cin >> var;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX / 2;
const ll LLINF = 1LL<<60;
constexpr ll MOD = 1000000007;
const double EPS = 1e-9;

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  ll N;
  cin >> N;
  vll A(N);
  rep(i, N) {
    cin >> A[i];
  }
  
  //偶数の時を処理 => 取りすぎることが起こる
  if(N % 2 == 0) {
    //合計
    vvll dp(N+4, vll(2));
    for(ll i=4; i<N+4; i++) {
      ll ii = i - 4;
      if(ii%2 != 0) {
        dp[i][0] = dp[i-1][0];
      } else {
        dp[i][0] = dp[i-2][0] + A[ii];
      }
      
      if(ii >= 1) {
        if(ii%2==0) {
          dp[i][1] = dp[i-1][1];
        } else {
          dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + A[ii];
        }
      }
    }
    
    ll fi = N+4-1;
    fin(max(dp[fi][0], dp[fi][1]));
    
    return 0;
  }
  
  //合計
  vvll dp(N+4, vll(3));
  for(ll i=4; i<N+4; i++) {
    ll ii = i - 4;
    //遅延0のときは，最後は取らない（1個多く取ってしまう）
    if(ii%2 != 0 || ii == N-1) {
      dp[i][0] = dp[i-1][0];
    } else {
      dp[i][0] = dp[i-2][0] + A[ii];
    }
    
    if(ii >= 1) {
      if(ii%2==0) {
        dp[i][1] = dp[i-1][1];
      } else {
        dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + A[ii];
      }
    }
    
    if(ii >= 2) {
      if(ii%2!=0) {
        dp[i][2] = dp[i-1][2];
      } else {
        dp[i][2] = max(max(dp[i-2][2], dp[i-3][1]), dp[i-4][0]) + A[ii];
      }
    }
  }
  
  ll fi = N+4-1;
  fin(max(max(dp[fi][0], dp[fi][1]), dp[fi][2]));
  
}