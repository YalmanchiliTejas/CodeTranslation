#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
using ll = long long;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define FOR(i,a,n) for(int i = (a); i < (n); ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int n, m;
bool edge[9][9];
int perm[9];

int main() {
  cin >> n >> m;
  int a, b; REP(i,m) {
    cin >> a >> b;
    edge[a][b] = edge[b][a] = true;
  }
  FOR(i,1,n+1) perm[i] = i;
  int ans = 0;
  do {
    bool f = true;
    FOR(i,1,n) if (!edge[perm[i]][perm[i+1]]) { f = false; break; }
    if (f) ans++;
  } while (next_permutation(perm+2, perm+n+1)) ;
  cout << ans << endl;
  return 0;
}