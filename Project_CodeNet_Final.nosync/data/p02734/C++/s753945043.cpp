#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

int main(){
  int n, s; cin >> n >> s; int a[n];
  rep(i, n){
    cin >> a[i];
  }
  ll dp[3010][3010] = {};  ll ans = 0; dp[0][0]=1;
  rep(i, n){
    dp[i+1][a[i]]+=(i+1); dp[i+1][a[i]]%=mod;
    rep(j, 3010){
      if(j!=0) dp[i+1][min(j+a[i], 3009)]+=dp[i][j]; dp[i+1][min(j+a[i], 3009)]%=mod;
      dp[i+1][j]+=dp[i][j]; dp[i+1][j]%=mod;
    }
    if(a[i]==s) ans+=(i+1)*(n-i);
    rep(j, 3010){
      if(a[i]+j==s && j!=0) ans+=(dp[i][j]*(n-i)); ans%=mod;
    }
  }
  cout << ans << endl;
}