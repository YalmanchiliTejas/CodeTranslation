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
#include <cstring>

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

string s;
int N, K;
int memo[1000][5][2];

int comb(int n, int r){
  if(r < 0 || n < r) return 0;
  if(r == 1) return n;
  if(r == 2) return n*(n-1)/2;
  return n*(n-1)*(n-2)/6;
}

int solve(int i, int k, int less){
  if(memo[i][k][less] != -1) return memo[i][k][less];
  if(k == 0) return memo[i][k][less] = 1;
  if(i == N) return memo[i][k][less] = 0;

  if(less) return memo[i][k][less] = comb(N-i, k)*pow(9, k);
  if(s[i] == '0') return memo[i][k][less] = solve(i+1, k, false);
  return memo[i][k][less] = solve(i+1, k, true)+solve(i+1, k-1, false)+solve(i+1, k-1, true)*(s[i]-'1');
}


signed main() {
  cin >> s >> K;
  N = s.size();

  memset(memo, -1, sizeof(memo));
  cout << solve(0, K, false) << endl;

  return 0;
}