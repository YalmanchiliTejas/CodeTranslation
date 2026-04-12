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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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


int calc(int a,int b){
  if(b == 0) return 1;
  if(b%2 == 0){
    int d = calc(a,b/2);
    return (d*d)%MOD;
  }
  return (a*calc(a,b-1))%MOD;
}

int comb(int n,int r){
  int tmp = 1,ttmp = 1;
  for(int i = n;i >= n-r+1;i--) tmp = (tmp*i)%MOD;
  for(int i = 1;i <= r;i++) ttmp = (ttmp*i)%MOD;
  return (tmp*calc(ttmp,MOD-2))%MOD;
}

int f(int n, int m, int k){
  int c = comb(n*m-2, k-2);
  int ans = 0;
  FOR(i, 1, n){
    (ans += (m*m*(n-i))%MOD*c*i%MOD) %= MOD;
  }

  return ans;
}
signed main() {
  int N, M, K;
  cin >> N >> M >> K;

  cout << (f(N, M, K)+f(M, N, K))%MOD << "\n";

  return 0;
}