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
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

ll n;
ll a[201010];
P b[201010];
ll res[201010];

int main(){
  cin>>n;
  rep(i,n){
    cin>>a[i];
    b[i]=P(a[i],i);
  }
  sort(b,b+n);
  ll m=(n+1)/2;
  m--;
  rep(i,n){
    if(i<=m)res[b[i].se]=b[m+1].fi;
    else res[b[i].se]=b[m].fi;
  }
  rep(i,n)cout<<res[i]<<endl;
  return 0;
}
