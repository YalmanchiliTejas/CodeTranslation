#include <bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
  #include "header.h"
#else
  #define debug(args...)
#endif

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long lli;
typedef long double ld;

#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(auto i=(a);i<b;i++)

#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
void preprocess(void) {
  return;
}
vi p, in, ss;
vector<vi> adj;
void dfs(int v, int par = -1) {
  int flag = 0;
  for(auto x: adj[v]) {
    if(x == par) continue;
    flag = 1;
    ss[v]++;
    p[x] = v;
    dfs(x, v);
  }
  if(!flag) in.pb(v);
}

vi matched;
int ans = 0;
void dfs1(int v, int par = -1) {
  for(auto x: adj[v])  {
    if(x == par) continue;
    dfs(x, v);
  }
  if(par != -1 && !matched[v]) {
    if(matched[par]) {
      ans = 1;
    }
    matched[par] = 1;
    matched[v] = 1;
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  preprocess();
  int n; cin>>n;
  adj.resize(n+1, vi(0));
  ss.resize(n+1);
  p.resize(n+1, -1);
  rep(i,0,n-1) {
    int x, y; cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  if(n%2) {
    cout<<"First"<<endl;
    return 0;
  }
  dfs(1, -1);
  int flag = 0; //flag = 0 => matching exists
  vi d(n+1);
  while(!in.empty()) {
    int x = in.back();
    in.pop_back();
    if(p[x] == -1 || d[p[x]]) {
      flag = 1;
      break;
    }
    d[x] = 1;
    d[p[x]] = 1;
    if(p[p[x]] != -1) {
      ss[p[p[x]]]--;
      if(ss[p[p[x]]] == 0) {
        in.pb(p[p[x]]);
      }
    }
  }
  if(flag) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
}

