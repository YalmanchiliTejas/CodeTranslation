#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

typedef long long ll;
typedef long double R;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int nmax=8;
bool graph[nmax][nmax];

// Problem Specific Parameter:

int dfs(int v, int n, bool visited[nmax]) {
  bool all_visited=true;
  for(int i = 0; i < n; ++i) {
    if(visited[i] == false) all_visited = false;
  }
  if(all_visited) return 1;

  int ret = 0;
  for(int i = 0; i < n; ++i) {
    if(graph[v][i] == false) continue;
    if(visited[i]) continue;
    visited[i] = true;
    ret += dfs(i, n, visited);
    visited[i] = false;
  }

  return ret;
}

int main() {
  int n, m; cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  bool visited[n];
  for(int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  visited[0] =true;

  cout << dfs(0, n, visited) << endl;

  return 0;
}