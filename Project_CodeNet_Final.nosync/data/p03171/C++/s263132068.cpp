#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[3010][3010];

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  for(int len=1;len<=n;len++){
    for(int i=0;i+len<=n;i++){
      int j=i+len;
      if((n-len)%2==0) dp[i][j]=max(a[i]+dp[i+1][j],dp[i][j-1]+a[j-1]);
      else dp[i][j]=min(-a[i]+dp[i+1][j],dp[i][j-1]-a[j-1]);
    }
  }
  cout << dp[0][n] << endl;
}