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
const int INF = 1e18;

using namespace std;


signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];

  int ans = 0;
  bool flag = false;
  while(!flag){
    REP(i, N){
      int cnt = A[i]/N;
      A[i] %= N;
      ans += cnt;
      REP(j, N){
        if(i == j) continue;
        A[j] += cnt;
      }

      if(i == N-1){
        REP(j, N){
          if(A[j] >= N) break;
          if(j == N-1) flag = true;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}