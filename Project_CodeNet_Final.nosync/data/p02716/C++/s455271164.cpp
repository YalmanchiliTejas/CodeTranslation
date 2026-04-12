#include<iostream>
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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n,0);
  rep(i,n){
    cin >> a[i];
  }

  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(3, vector<ll>(2,-longinf)));
  dp[0][1][0] = 0;
  rep(i,n){
    if(i%2){
      dp[i+1][0][0] = max(dp[i][1][0],dp[i][1][1]);
      dp[i+1][1][0] = max(dp[i][2][0],dp[i][2][1]);
      dp[i+1][1][1] =     dp[i][1][0]+a[i];
    } else {
      dp[i+1][1][0] = max(dp[i][1][0],dp[i][1][1]);
      dp[i+1][1][1] =     dp[i][0][0]+a[i];
      dp[i+1][2][1] =     dp[i][1][0]+a[i];
    }
  }
  cout << max(dp[n][1][0],dp[n][1][1]) << endl;
  return 0;
}
