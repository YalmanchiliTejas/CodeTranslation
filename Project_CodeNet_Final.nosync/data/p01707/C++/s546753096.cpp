#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3
#define MAX_N 10000
#define mod 1000000007LL

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
}

ll n,d,x;
ll dp[2222][2222];
ll sum[2222];

int main(){
	cin.sync_with_stdio(false);
  while(1){
    cin>>n>>d>>x;
    if(n==0&&d==0)break;
    if(x==1){
      cout<<0<<endl;
      continue;
    }
    int maxd=min(d,n);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    rep(i,maxd){
      memset(sum,0,sizeof(sum));
      rep(j,n){
        sum[j+1]=(dp[i][j]+sum[j])%mod;
      }
      rep(j,n+1){
        dp[i+1][j]=(sum[j]-sum[max(0LL,j-x+1)]+mod*2)%mod;
      }
    }

    ll res=0;
    d%=mod;
    repl(i,1,maxd+1){
      // calc dCi
      ll comb=1;
      rep(j,i){
        comb=comb*((d-j+mod*2)%mod)%mod;
        comb=comb*mod_pow(i-j,mod-2)%mod;
      }
      res=(res+comb*dp[i][n]%mod)%mod;
    }
    cout<<res<<endl;

  }
  return 0;
}