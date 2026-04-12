#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 998244353
#define llMAX 9223372036854775807
#define llMIN -9223372036854775808
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

ll n,s;

int main(){
  ll ans=0;
 cin >> n >> s;
  vi a(n),dp(s+1,0),dp2(s+1,0);
  REP(i,n) cin>>a[i];

  dp[0]=1;
  dp2[0]=1;
  REP(i,n){
    ll aa=a[i];
    for(ll j=0;j<s+1;j++){
      if ((j+aa)<(s+1)){
        if (j==0){
          dp2[j+aa]=(dp[j+aa]+dp[j]*(i+1)%MOD)%MOD;
        }else{
          dp2[j+aa]=(dp[j+aa]+dp[j])%MOD;
        }
      }
    }
    
    ll xxx=(dp2[s]-dp[s]+MOD)%MOD;
    xxx=xxx*(n-i)%MOD;
    ans=(ans+xxx)%MOD;
    for(ll j=0;j<s+1;j++)
      dp[j]=dp2[j];

  }

  cout<<ans<<endl;
  return 0;
}