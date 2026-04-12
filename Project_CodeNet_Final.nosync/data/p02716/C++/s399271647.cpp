#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <unordered_map>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
ll pow(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = pow(N, P/2);
        return t*t;
    }
    return N * pow(N, P-1);
}
ll modpow(ll N, ll P,ll k){
    if(P==0) return 1;
    if(P%2==0){
        ll t = modpow(N, P/2,k)%k;
        return t*t%k;
    }
    return N * modpow(N, P-1,k)%k;
}
ll modkai(ll n,ll m,ll k){//n*(n-1)*(n-2)*...(m+1)%k
    if(n == m)return 1;
    return modkai(n-1,m,k)*n%k;
}
ll mod_cnb(ll n,ll m,ll k){//nCm%k,kは十分大きい素数
  int m_=modkai(m,0,k);
  return modkai(n,n-m,k)*modpow(m_,k-2,k)%k;
}
ll gcd(ll n,ll m){
    ll n_ = max(n,m);
    ll m_ = min(n,m);
    if(n_%m_ == 0)return m_;
    return gcd(m_,n_%m_);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}

int main(){
    int n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll dp[100000][3];
    ////even///
    if(n%2==0){
        ll d[100000][2];
      d[0][0]=a[0];
      d[0][1]=a[1];
      rep(i,n/2-1){
        d[i+1][0]=d[i][0]+a[(i+1)*2];
        d[i+1][1]=max(d[i][1]+a[(i+1)*2+1],d[i][0]+a[(i+1)*2+1]);
    }
        cout<< max(d[n/2-1][0],d[n/2-1][1])<<endl;
        return 0;
    }
    ////odd/////
    ll t=n/2-1;
    dp[0][0]=a[0];
    dp[0][1]=a[1];
    dp[0][2]=a[2];
    rep(i,t){
        dp[i+1][0]=dp[i][0]+a[(i+1)*2];
        dp[i+1][1]=max(dp[i][1]+a[(i+1)*2+1],dp[i][0]+a[(i+1)*2+1]);
        dp[i+1][2]=max(dp[i][0]+a[(i+1)*2+2],max(dp[i][2]+a[(i+1)*2+2],dp[i][1]+a[(i+1)*2+2]));
    }
    ll ans=max(dp[t][2],dp[t][1]);
  ans=max(ans,dp[t][0]);
    cout <<ans<<endl;
}