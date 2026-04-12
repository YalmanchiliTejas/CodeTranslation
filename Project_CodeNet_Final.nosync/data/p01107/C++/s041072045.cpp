#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int32 n,m;
vector<string> c;

int32 dy[4] = {0,1,0,-1};
int32 dx[4] = {-1,0,1,0};

bool dfs(int32 y, int32 x,int32 dir = 2){
  // cout << y << " " << x << " " << dir <<  "\n";
  if(y == n-1 && x == 0)return true;
  if(c[y][x] == '#')return false;
  c[y][x] = '#';
  dir = (dir-1+4)%4;
  REP(k,4){
    int32 ny = y+dy[(dir+k)%4];
    int32 nx = x+dx[(dir+k)%4];
    if(ny < 0 || n <= ny)continue;
    if(nx < 0 || m <= nx)continue;
    if(dfs(ny,nx,(dir+k)%4))return true;
  }
  return false;
}

void solve(){
  c = vector<string>(n);
  REP(i,n)cin >> c[i];
  REP(lp,4){
    if(!dfs(0,0)){
      // REP(i,n){
      //   cout << c[i] << "\n";
      // }
      // cout << "\n";

      ANS("NO");
      return;
    }
    // REP(i,n){
    //   cout << c[i] << "\n";
    // }
    // cout << "\n";

    vector<string> tmp = c;
    c = vector<string>(m,string(n,'*'));
    REP(i,m){
      REP(j,n){
        c[i][j] = tmp[n-j-1][i];
      }
    }
    swap(n,m);
  }
  ANS("YES");
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(true){
    cin >> n >> m;
    if(n==0)return 0;
    solve();
  }
  return 0;
}
