#include<bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll,ll> Pll;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

ll dp[10010][110];
ll sum[210];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string K;cin>>K;
  ll D;cin>>D;
  ll d=0;
  while(d<10){
    d+=D;
  }
  dp[K.length()][0]=1;
  //debug(d);
  for(ll i=K.length()-1;i>=0;i--){
    sum[0]=dp[i+1][0];
    for(ll j=1;j<2*d;j++){
      sum[j] = (sum[j-1]+dp[i+1][j%D])%MOD;
    }
    //debugArray(sum,D);
    for(ll j=0;j<d;j++){
      dp[i][j] = (sum[j+d]-sum[j-10+d]+MOD)%MOD;
    }
  }
  ll ans = 0;
  sum[0]=0;
  for(ll i=0;i<(ll)K.length();i++){
    ll k=K[i]-'0';
    for(ll j=0;j<k;j++){
      ll n=(d+D-sum[0]-j)%D;
      //debug(n);
      ans = (ans+dp[i+1][n])%MOD;
      //debug(ans);
    }
    sum[0] = (sum[0]+k)%D;
  }
  ans = (ans-1+MOD)%MOD;
  if(sum[0]%D==0){
    ans=(ans+1)%MOD;
  }
  cout<<ans<<endl;
  return 0;
}
