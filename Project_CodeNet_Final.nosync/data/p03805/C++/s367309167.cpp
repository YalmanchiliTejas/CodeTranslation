#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <numeric>

#define rep(i,n) for(int i = 0;i < (n);i++)
#define repp(i,j, n) for(int i = (j);i < (n);i++)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define INF 1e9

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pair<int, int> > vpi;
typedef vector<pair<ll, ll> > vpl;

int n, m;
vvi a;
int ans = 0;
vi flag;


void dfs(int v, int cnt){
  for(auto i : a[v]){
    if(flag[i] > 0) continue;
    flag[i] = 1;
    if(cnt+1 == n-1) ans++;
    else dfs(i, cnt+1);
    flag[i] = 0;
  }
  return;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  a = vvi(n);
  rep(i, m){
    int x, y;
    cin >> x >> y;
    x--;y--;
    a[x].pb(y);
    a[y].pb(x);
  }
  flag = vi(n+10);
  flag[0] = 1;
  dfs(0, 0);
  cout << ans << endl;

  return 0;
}
