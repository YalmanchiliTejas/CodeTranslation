#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N, M; 
  cin >> N >> M;

  vector<vector<bool>> graph(N, vector<bool>(N, false));
  REP(i, M){
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u][v] = true;
    graph[v][u] = true;
  }

  int ans = 0;
  vector<int> vec(N-1);
  REP(i, N-1) vec[i] = i+1;
  do{
    bool ok = true;
    REP(i, N-1){
      if(i == 0){
        if(!graph[0][vec[i]]) ok = false;
      }else{
        if(!graph[vec[i]][vec[i-1]]) ok = false;
      }
    }
    if(ok) ans++;
  }while(next_permutation(ALL(vec)));

  cout << ans << endl;

  return 0;
}