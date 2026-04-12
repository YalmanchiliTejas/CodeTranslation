#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
#define PER(i,n) for(int i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int n;

int dfs(int v, const vii &g, vb &seen) {
  seen[v] = true;
  int res = 0;
  bool ok = true;
  rep(i,n) if(seen[i] == false) ok = false;
  if(ok) res++;
  for(int nv : g[v]) {
    if(seen[nv]) continue;
    res += dfs(nv, g, seen);
  }
  seen[v] = false;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;
  vii g(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vb seen(n);
  int s = 0;
  int ans = dfs(s,g,seen);
  cout << ans << endl;
}