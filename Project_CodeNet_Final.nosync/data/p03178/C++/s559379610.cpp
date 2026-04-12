#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;

#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define absd(x) (x<0?-(x):x)
#define pow2(x) ((x)*(x))
#define rep(i,n) for(int i=0; i<n; ++i)
#define repr(i,n) for(int i=n-1; i>=0; --i)
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define replr(i,s,n) for(int i=n; i>=s; --i)
#define repf(i,s,n,j) for(int i=s; i<=n; i+=j)
#define repe(e,obj) for(auto e : obj)

#define SP << " " <<
#define COL << " : " <<
#define COM << ", " <<
#define ARR << " -> " <<
#define PNT(STR) cout << STR << endl
#define POS(X,Y) "(" << X << ", " << Y << ")"
#define DEB(A) " (" << #A << ") " << A
#define DEBREP(i,n,val) for(int i=0; i<n; ++i) cout << val << " "; cout << endl
#define ALL(V) (V).begin(), (V).end()
#define INF 1000000007
#define INFLL 1000000000000000007LL
#define EPS 1e-9

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define P_TYPE int
typedef pair<P_TYPE, P_TYPE> P;
typedef pair<P, P_TYPE> PI;
typedef pair<P_TYPE, P> IP;
typedef pair<P, P> PP;
typedef priority_queue<P, vector<P>, greater<P> > pvqueue;

#define N 10003
#define D 101
#define MOD 1000000007

string k;
int n, d;
ll dp[N][D][2];

int main() {
  cin >> k >> d;
  n = k.length();
  rep(i, n+1) rep(j, d) rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i, n) {
    int v = k[i] - '0';
    rep(j, d) {
      rep(k, 2) {
        dp[i][j][k] %= MOD;
        rep(w, 10) {
          if(!k && v < w) continue;
          dp[i+1][(j+w) % d][k | (w < v)] += dp[i][j][k];
        }
      }
    }
  }
  cout << (dp[n][0][0] + dp[n][0][1] - 1) % MOD << endl;

  return 0;
}