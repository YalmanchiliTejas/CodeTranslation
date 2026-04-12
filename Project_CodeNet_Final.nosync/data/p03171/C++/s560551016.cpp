#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/
int n, a[3000];

int memo[2][3010][3010];
bool vis[2][3010][3010];

int dfs(int t, int l, int r){
  if(r < l) return 0;
  if(vis[t][l][r]) return memo[t][l][r];
  vis[t][l][r] = true;
  
  if(t == 0){
    int res = -inf;
    chmax(res, dfs((t+1)%2, l+1, r)+a[l]);
    chmax(res, dfs((t+1)%2, l, r-1)+a[r]);
    return memo[t][l][r] = res;
  }else{
    int res = inf;
    chmin(res, dfs((t+1)%2, l+1, r)-a[l]);
    chmin(res, dfs((t+1)%2, l, r-1)-a[r]);
    return memo[t][l][r] = res;
  }
}

signed main(){
  cin >> n;
  rep(i, 0, n) cin >> a[i];

  cout << dfs(0, 0, n-1) << endl;

  return 0;
}
