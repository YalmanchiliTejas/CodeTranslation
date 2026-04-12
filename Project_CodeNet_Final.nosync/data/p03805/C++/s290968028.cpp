#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int n,m;
bool seen[8] = {false};

int dfs(int v, int cnt, vvi &G){
  if(cnt == n-1) return 1;

  seen[v] = true;
  int ret = 0;
  for(int nv : G[v]){
    if(seen[nv]) continue;
    ret += dfs(nv, cnt+1, G);
  }
  seen[v] = false;

  return ret;
}

int main(){
  cin >> n >> m;
  vvi G(n);
  rep(i, m){
    int a,b; cin >> a >> b;
    a--; b--;
    G[a].pb(b); G[b].pb(a);
  }

  std::cout << dfs(0, 0, G) << '\n';
}
