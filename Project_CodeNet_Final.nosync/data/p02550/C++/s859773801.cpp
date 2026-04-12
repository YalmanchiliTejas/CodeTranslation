#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int N, X, M;
  cin >> N >> X >> M;
  

  int now = X;

  vector<int> used(M, -1);
  used[now] = 0;

  
  int cnt = 1;
  int loop = 1;
  REP(i, N){
    now = (now*now)%M;
    if(used[now] != -1){
      loop = cnt-used[now];
      break;
    }
    used[now] = cnt++;
  }

  N -= used[now];
  cnt = (N)/loop;

  int ans = 0;
  REP(i, M){
    if(used[i] == -1) continue;
    if(used[i] < used[now]) ans += i;
    else{
      ans += cnt*i;
      if(used[i]-used[now] < N%loop) ans += i;
    }
  }

  cout << ans << "\n";

  return 0;
}
