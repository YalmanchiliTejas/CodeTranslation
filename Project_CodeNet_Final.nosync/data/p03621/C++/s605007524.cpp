#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
    return powmod(a, MOD-2);
}
ll f[20020], invf[20020];
void fac(int n){
    f[0]=1;
    for(ll i=1; i<=n; i++) f[i]=f[i-1]*i%MOD;
    invf[n]=inv(f[n]);
    for(ll i=n-1; i>=0; i--) invf[i]=invf[i+1]*(i+1)%MOD;
}
ll comb(int x, int y){
    if(!(0<=y && y<=x)) return 0;
    return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
  string a, b; cin>>a>>b;
  int n=a.size();
  fac(2*n);
  int x=0, y=0;
  for(int i=0; i<n; i++){
    if(a[i]=='1'){
      if(b[i]=='0') x++;
      else y++;
    }
  }
  ll dp[2][10010]={};
  dp[0][0]=1;
  for(int i=1; i<=x; i++){
    fill(dp[i&1], dp[i&1]+y+1, 0);
    for(int j=0; j<=y; j++){
      if(j) (dp[i&1][j]+=dp[i&1][j-1]*i*j)%=MOD;
      (dp[i&1][j]+=dp[(i&1)^1][j]*i*i)%=MOD;
    }
  }
  ll ans=0;
  for(int i=0; i<=y; i++){
    (ans+=f[y]*invf[y-i]%MOD*f[x+y]%MOD*invf[x+y-i]%MOD*dp[x&1][y-i])%=MOD;
  }
  cout<<ans<<endl;
	return 0;
}