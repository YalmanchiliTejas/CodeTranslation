#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

#define vint(v, n) vector<int> v(n); REP(i,n) cin >> v[i];
#define vvint(v, w, n) vector<int> v(n); vector<int> w(n); REP(i,n) cin >> v[i] >> w[i];
#define vlint(v, n) vector<ll int> v(n); REP(i,n) cin >> v[i];
#define vdouble(v, n) vector<double> v(n); REP(i,n) cin >> v[i];
#define vvdoube(v, n1, n2) vector<vector<double> > v(n1, vector<double>(n2, 0)); REP(i,n1) REP(j,n1) cin >> v[i][j];
#define string(x) string x; cin >> x;
#define vstring(v, n) vector<string> v(n); REP(i,n){string a; std::cin >> a; v.push_back(a); }

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).begin(), (v).end(), std::greater<int>()
#define len(v) (v).length()
#define FIND(s, n) (s.find(n) != s.end())
#define SORT(a) sort(all(a))

static const string abet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
static const long long MOD = 1000000007;
static const double PI=3.1415926535897932;
static const int INF = 0x3f3f3f3f;
static const int INFTY = (1 << 29);
static const long long LINFTY = (1LL << 32);

static const int dy4[]={0, 0, 1, -1};
static const int dx4[]={1, -1, 0, 0};
static const int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
static const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int G[8][8];

int dfs(int v, int N, bool visited[]){

  bool all_visited=true;
  REP(i, N) if(visited[i]==false) all_visited=false;
  if(all_visited) return 1;

  int ret = 0;

  REP(i, N){
    if(G[v][i]==false) continue;
    if(visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, N, visited);
    visited[i] = false;
  }

  return ret;
}

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  REP(i, M){
    int A, B;
    cin >> A >> B;
    G[A-1][B-1]=G[B-1][A-1]=true;
  }

  bool visited[8];
  REP(i, N) visited[i]=false;

  visited[0]=true;
  cout << dfs(0, N, visited) << endl;

  return 0;
}
