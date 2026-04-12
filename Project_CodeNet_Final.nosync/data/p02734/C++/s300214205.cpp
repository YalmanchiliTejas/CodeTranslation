#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll DP[3005][3005];

int main() {
  int N, S;
  cin>>N>>S;
  int tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    DP[i][0]++;
    DP[i][0] %= mod1;
    if(i==0) {
      DP[0][tmp]++;
    }
    else {
      DP[i][tmp]++;
      for(int j=0;j<=S;++j) {
        DP[i][j] += DP[i-1][j];
        DP[i][j] %= mod1;
        if(j+tmp<=S) {
          DP[i][j+tmp] += DP[i-1][j];
          DP[i][j+tmp] %= mod1;
        }
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<N;++i) {
    ans += DP[i][S];
    ans %= mod1;
  }
  cout<<ans<<endl;
}

