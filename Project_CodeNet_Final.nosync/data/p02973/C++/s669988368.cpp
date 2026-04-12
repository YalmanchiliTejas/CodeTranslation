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

int main(){
  int N;
  cin >> N;
  ll a[N];
  rep(i, N){
    cin >> a[i]; a[i] = -a[i];
  }
  ll dp[N] = {}; rep(i, N)dp[i]=inf;
  rep(i, N){
    *upper_bound(dp, dp+N, a[i]) = a[i];
  }
  cout << lower_bound(dp, dp+N, inf) - dp << endl;
}