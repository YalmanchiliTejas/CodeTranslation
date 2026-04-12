#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include<deque>
#include<stdlib.h>
#include <algorithm>
#include<set>
#include<map>
#include <limits>
#include<iomanip>
#include<string>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
#define d_5 100000
#define d9_7 1000000007
long long modinv(long long a, long long m) {//modの逆元
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}
ll Factrial(ll num){
  if(num==1||num==0){
    return 1;
  }else if(num<0){
    printf("ERROR_minus\n");
    return 0;
  }else{
    return (num*Factrial(num-1))%d9_7;
  }
}
ll linercomb(ll n,ll k, ll mod){//n,kの線形時間で求める
  ll ans=1;
  for(ll i=n;i>=n-k+1;i--){
    ans*=i;
    ans%=mod;
  }
  ll k1=Factrial(k);
  k1%=mod;
  ans*=modinv(k1,mod);
  ans%=mod;
  return ans;
}
int main(void){
  ll n,m,k;
  cin>>n>>m>>k;
  ll sum1=0;
  for(ll i=1;i<=n-1;i++){
    sum1+=(n-i)*i;//iが距離
    sum1%=d9_7;
  }
  sum1*=m*m;
  sum1%=d9_7;
  ll sum2=0;
  for(ll i=1;i<=m-1;i++){
    sum2+=(m-i)*i;//iが距離
    sum2%=d9_7;
  }
  sum2*=n*n;
  sum2%=d9_7;
  sum1+=sum2;
  cout<<(sum1*linercomb(n*m-2,k-2,d9_7))%d9_7<<endl;
  return 0;
}