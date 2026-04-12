#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

ll bik[1010][1010];

ll modinv(ll a) {
    ll m=Mod;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main(){
  ll i,j,k;
  ll n,x;
  bik[0][1]=1;
  bik[1][1]=1;
  for(i=2;i<1010;i++) bik[i][1]=(bik[i-1][1]*i)%Mod;
  for(i=0;i<1010;i++){
    for(j=2;j<1010;j++){
      bik[i][j]=(bik[i][j-1]*bik[i][1])%Mod;
    }
  }
  cin>>n;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;

  VVI dp(n+2,VI(n+2,0));

  dp[b+1][0]=1;
  for(i=b;i>=a;i--){
    for(j=0;j<=n;j++){
      dp[i][j]+=dp[i+1][j];
      for(k=c;k<=d;k++){
        if(j-k*i>=0) {
          ll s=n-j+k*i;
           dp[i][j]+=((dp[i+1][j-k*i]* bik[s][1])%Mod) * modinv((((bik[s-i*k][1] * bik[i][k])%Mod)*bik[k][1])%Mod);
           dp[i][j]%=Mod;
        }
      }
    }
  }
  cout<<dp[a][n]<<endl;

  return 0;
}