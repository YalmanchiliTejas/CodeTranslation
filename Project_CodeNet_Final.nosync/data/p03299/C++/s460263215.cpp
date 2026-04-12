#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

ll dp[111][111][2];
int a[111];

ll powmod(ll n,ll k){
    ll ret=1;
    while(k>0){
        if(k&1)ret=ret*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return ret;
}

ll rec(int l,int r,int h,int flag){
    if(dp[l][r][flag]!=-1)return dp[l][r][flag];
    if(l+1==r){
        if(flag)return dp[l][r][flag]=powmod(2,a[l]-h);
        else return dp[l][r][flag]=0;
    }
    int mi=inf,ma=0;
    REP(i,l,r){
        mi=min(mi,a[i]);
        ma=max(ma,a[i]);
    }
    ll ret1=1;
    ll pos=l-1;
    REP(i,l,r){
        if(a[i]==mi){
            if(i-pos>1)ret1*=rec(pos+1,i,mi,1);
            ret1%=mod;
            pos=i;
        }
    }
    if(r-pos>1)ret1=ret1*rec(pos+1,r,mi,1)%mod;
    ret1=ret1;
    if(flag) return dp[l][r][flag]=ret1*powmod(2,mi-h)%mod;
    ll ret2=1;
    pos=l-1;
    REP(i,l,r){
        if(a[i]==mi){
            ret2=2*ret2%mod;
            if(i-pos>1)ret2*=(2*rec(pos+1,i,mi,1)+rec(pos+1,i,mi,0));
            ret2%=mod;
            pos=i;
        }
    }
    if(r-pos>1)ret2=ret2*(2*rec(pos+1,r,mi,1)+rec(pos+1,r,mi,0))%mod;
    ret2=(ret2-ret1*2+2*mod)%mod;
    return dp[l][r][flag]=ret2;
}
int main(){
   int n;
   cin>>n;
   rep(i,n)cin>>a[i];
   rep(i,n+1)rep(j,n+1)rep(k,2)dp[i][j][k]=-1;
   ll ans=rec(0,n,0,0)+rec(0,n,0,1);
   cout<<ans%mod<<endl;
   return 0;
}
