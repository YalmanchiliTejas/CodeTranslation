#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

#define MAX_N 2002
ll inv[MAX_N+10],fac[MAX_N+10],ifac[MAX_N+10];

void setComb(){
  inv[0]=1;inv[1]=1;fac[1]=1;ifac[1]=1;fac[0]=1;ifac[0]=1;
  for(int i=2;i<MAX_N;i++){
    inv[i]=(-MOD/i)*inv[MOD%i]%MOD;
    fac[i]=fac[i-1]*i%MOD;
    ifac[i]=ifac[i-1]*inv[i]%MOD;

    inv[i]=(inv[i]+MOD)%MOD;
    fac[i]=(fac[i]+MOD)%MOD;
    ifac[i]=(ifac[i]+MOD)%MOD;
  }
  return;
}

ll comb(ll n,ll k){
  if(n<k||n<0||k<0) return 0;
  else return ((fac[n]*ifac[k]%MOD*ifac[n-k]%MOD+MOD)%MOD);
}

ll hcomb(ll n,ll r){
  if(n==0&&r==0) return 1;
  else if(n<0||r<0) return 0;
  else return comb(n+r-1,r-1);
}

int N,A,B,C,D;
ll dp[1001][1001];

ll coef[1001];

void add(ll &a,ll b){
    a=(a+b)%MOD;
}

void mul(ll &a,ll b){
    a=a*b%MOD;
}

ll rec(int ma,int rest){
    if(rest==0) return 1;
    if(ma<A) return 0;
    if(dp[ma][rest]>=0) return dp[ma][rest];

    ll res=0;
    add(res,rec(ma-1,rest));

    ll c=coef[ma];
    for(int i=C;i<=D;i++){
        if(i*ma>rest) break;
        
        if(i>C) mul(c,comb(i*ma,ma));
        ll cost=c;
        mul(cost,comb(rest,i*ma));
        mul(cost,ifac[i]);

        ll tmp=rec(ma-1,rest-(i*ma));
        mul(tmp,cost);
        add(res,tmp);
    }
    return dp[ma][rest]=res;
}

int main(){
  cin>>N>>A>>B>>C>>D;

  for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) dp[i][j]=-1;

  setComb();
  for(int i=A;i<=B;i++){
      coef[i]=1;
      if(i*C>N) break;
      for(int j=0;j<C;j++){
          mul(coef[i],comb(i*C-i*j,i));
      }
  }

  cout<<rec(B,N)<<endl;

  return 0;
}
