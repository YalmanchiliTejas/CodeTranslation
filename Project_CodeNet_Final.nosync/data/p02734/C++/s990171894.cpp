#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll DP[3005][3005];

int main() {
  ll mod = 998244353;
  int N, S;
  cin>>N>>S;
  int A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  DP[0][0] = 1;
  DP[0][A[0]] = 1;
  for(int i=1;i<N;++i) {
    DP[i-1][0]++;
    DP[i-1][0] %= mod;
    for(int j=0;j<=S;++j) {
      if(j-A[i]>=0) {
        DP[i][j] += DP[i-1][j-A[i]];
        DP[i][j] %= mod;
      }
      DP[i][j] += DP[i-1][j];
      DP[i][j] %= mod;
    }
  }
  /**
  for(int i=0;i<N;++i) {
    for(int j=0;j<=S;++j) {
      cout<<DP[i][j]<<" ";
    }
    cout<<endl;
  }
  **/
  ll ans = 0;
  for(int i=0;i<N;++i) {
    ans += DP[i][S];
    ans %= mod;
  }
  cout<<ans<<endl;
}

