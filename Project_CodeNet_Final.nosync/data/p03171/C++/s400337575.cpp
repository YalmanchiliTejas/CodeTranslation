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
  ll dp[N+1][N+1];
  rep(i, N+1){
    dp[i][i]=0;
  }
  for(int len=1; len<=N; len++){
    for(int i=0; i+len<=N; i++){
      int j = i+len;
      if((N-(j-i))%2) dp[i][j] = min(dp[i][j-1]-a[j-1], dp[i+1][j]-a[i]);
      else dp[i][j] = max(dp[i][j-1]+a[j-1], dp[i+1][j]+a[i]);
    }
  }
  cout << dp[0][N] << endl;
}