#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int32 n;
vector<int64> a;
vector<int64> asum;  //2-indexed

map<pll,int64> memo;

int64 dfs(int64 i, int64 x){  //i以降からx個使う
  if(x == 0)return 0;
  if(memo.count(pll(i,x)) >= 1)return memo[pll(i,x)];
  if(n - i == x * 2 - 1){
    return memo[pll(i,x)] = asum[n+1] - asum[i];
  }
  // if(n - i == x * 2){
  //   int64 ret = -LLINF;
  //   REP(j,x+1){
  //     int64 y = asum[i+2*j] - asum[i] + asum[n+1] - asum[2*j+1];
  //     // cout << j << " " << y << endl;
  //     ret = max(ret,y);
  //   }
  //   return ret;
  // }
  int64 ret = -LLINF;
  for(int32 j = 0;;++j){
    if(n-i-j < x * 2 - 1)break;
    ret = max(ret, a[i+j] + dfs(i+j+2,x-1));
  }
  return memo[pll(i,x)] = ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  REP(i,n)cin >> a[i];
  asum.resize(n+2,0);
  REP(i,n)asum[i+2] += asum[i] + a[i];
  int64 ans = -LLINF;
  // if(n % 2 == 0){
  //   REP(i,n/2+1){
  //     int64 x = asum[2*i] + asum[n+1] - asum[2*i+1];
  //     // cout << i << " " << x << endl;
  //     ans = max(ans,x);
  //   }
  // }else{

  // }
  ans = dfs(0,n/2);
  ANS(ans);
  return 0;
}