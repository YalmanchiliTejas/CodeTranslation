#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll mod_pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
    sum%=mod;
  }
  sum=sum*sum%mod;
  rep(i,n){
    sum=(sum-(a[i]*a[i]%mod)+mod)%mod;
  }
  sum*=mod_pow(2,mod-2);
  sum%=mod;
  cout<<sum<<endl;

  return 0;
}
