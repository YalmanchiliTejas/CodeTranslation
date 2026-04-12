#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--)
#define reprev(i,n) reprrev(i,0,n)
using namespace std;
#define sz(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define pb push_back
#define mp make_pair
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll INF = 1LL<<60;
 
const int MAX = 510000;
const int MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
struct UnionFind {
    vector<int> par, rank;
 
    UnionFind(int n) : par(n , -1), rank(n, 0) { }
    void init(int n) { par.assign(n, -1), rank.assign(n, 0); }
 
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
 
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
 
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};
 
const int nmax = 8;
vector<int> graph[nmax];
 
int dfs(int v, int N, bool visited[nmax]){
  bool all_visited = true;
  
  rep(i,N){
    if(visited[i]==false)
      all_visited = false;
  }
  if(all_visited) return 1;
  
  int ret=0;
  
  for(auto next : graph[v]){
    if(visited[next]) continue;
    
    visited[next] = true;
    ret += dfs(next,N,visited);
    visited[next] = false;
  }
  return ret;
}
 
int main(){
    int N,M;
  	cin >> N >> M;
  	rep(i,M) {
      int a,b;
      cin >> a >> b;
      graph[a-1].pb(b-1);
      graph[b-1].pb(a-1);
    }
  
  	bool visited[nmax];
  	rep(i,N) visited[i]=false;
  
  	visited[0] = true;
  	cout << dfs(0,N,visited) << endl;
}
