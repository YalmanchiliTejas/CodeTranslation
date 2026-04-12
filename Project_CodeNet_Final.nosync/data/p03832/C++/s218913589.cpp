#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[1010][1010];
ll comb[1010][1010];

#define N 1010
ll inv[N],fac[N],ifac[N];

int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;

  inv[0]=1;inv[1]=1;fac[1]=1;ifac[1]=1;fac[0]=1;ifac[0]=1;
  for(int i=2;i<=1010;i++){
    inv[i]=(-MOD/i)*inv[MOD%i]%MOD;
    fac[i]=fac[i-1]*i%MOD;
    ifac[i]=ifac[i-1]*inv[i]%MOD;
    //cout<<inv[i]<<" "<<fac[i]<<" "<<ifac[i]<<endl;
  }

  for(int i=0;i<=1001;i++) dp[i][0]=1;

  for(int i=a;i<=b;i++){
    for(int j=0;j<=n;j++){
      if(dp[i-1][j]==0) continue;
      if(j>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
      ll tmp=1;
      for(int k=1;k<=d&&j+i*k<=n;k++){
        tmp=tmp*fac[n-j-i*(k-1)]%MOD*ifac[i]%MOD*ifac[n-j-i*k]%MOD*inv[k]%MOD;
        if(k>=c){
          dp[i][j+i*k]=(dp[i][j+i*k]+dp[i-1][j]*tmp%MOD+MOD)%MOD;
        }
      }
    }
  }

  cout<<dp[b][n]<<endl;

  return 0;
}
