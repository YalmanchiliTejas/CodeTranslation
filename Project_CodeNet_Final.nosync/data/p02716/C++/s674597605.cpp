#include<iostream>
#include<string>
#include<cstring>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793

int main(){
  int N; cin >> N; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  ll dp[N+1][2] = {};
  dp[2][0] = a[0], dp[2][1] = a[1];
  dp[3][0] = max({a[0], a[1], a[2]});
  dp[3][1] = dp[3][0];
  for(int i=4; i<=N; i++){
    if(i%2==0){
      dp[i][1] = max({dp[i-2][0], dp[i-2][1]}) + a[i-1];
      dp[i][0] = dp[i-2][0] + a[i-2];
    }
    else{
      dp[i][1] = max({dp[i-1][1], dp[i-1][0], dp[i-2][0]+a[i-1]});
      dp[i][0] = dp[i][1];
    }
  }
  cout << max(dp[N][0], dp[N][1]) << endl;
}