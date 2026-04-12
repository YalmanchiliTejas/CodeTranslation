#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int main() {
  ll n,x,m;
  cin >> n >> x >> m;
  vl fx(m+1,-1),a;
  int len = 0;
  ll ans = 0,tot = 0;
  while(fx[x] == -1){
    tot+=x;
    a.push_back(x);
    fx[x] = len;
    len++;
    x= (x*x)%m;
  }
  if(n <= len){
    rep(i,n)ans+=a[i];
  }else{
    ans+=tot;
    n-=len;
    ll c = len-fx[x];
    ll loopCnt = n/c;
    ll loopSum = 0;
    for(int i=fx[x];i<len;i++)loopSum+=a[i];
    ans+= loopCnt*loopSum;
    n%=c;
    rep(i,n)ans+=a[fx[x]+i];
  }
  cout<<ans<<endl;
  return 0;
}