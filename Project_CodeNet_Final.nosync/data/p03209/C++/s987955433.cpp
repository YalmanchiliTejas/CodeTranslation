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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

int all[51];
int pate[51];

int dfs(int level, int remain){
  int ret = 0;

  if(remain >= 1) remain--;

  if(remain >= 1){
    if(all[level-1] <= remain){
      remain -= all[level-1];
      ret += pate[level-1];
    }else{
      ret += dfs(level-1, remain);
      remain = 0;
    }
  }

  if(remain >= 1){
    remain--;
    ret++;
  }

  if(remain >= 1){
    if(all[level-1] <= remain){
      remain -= all[level-1];
      ret += pate[level-1];
    }else{
      ret += dfs(level-1, remain);
      remain = 0;
    }
  }

  if(remain >= 1) remain--;

  return ret;
}

signed main() {
  int N, X; 
  cin >> N >> X;

  all[0] = 1;
  pate[0] = 1;
  FOR(i, 1, 50){
    all[i] += all[i-1]*2+3;
    pate[i] += pate[i-1]*2+1;
  }

  cout << dfs(N, X) << "\n";

  return 0;
}