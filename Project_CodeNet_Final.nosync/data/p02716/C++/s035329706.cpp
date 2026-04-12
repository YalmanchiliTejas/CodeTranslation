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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  vector<ll> a(n+2,-INF),pre(n+2,-1),nxt(n+2,-1);
  repl(i,1,n+1)cin>>a[i];
  rep(i,n+2){
    pre[i]=i-1;
    nxt[i]=i+1;
  }

  set<P> st;
  rep(i,n+2){
    st.insert(P(a[i],i));
  }

  ll sum=0;
  rep(_,n/2){
    P p=*st.rbegin();
    sum+=p.fi;
    ll idx=p.se;

    st.erase(st.find(P(p.fi,p.se)));
    st.erase(st.find(P(a[pre[idx]],pre[idx])));
    st.erase(st.find(P(a[nxt[idx]],nxt[idx])));

    ll val=a[pre[idx]]+a[nxt[idx]]-a[idx];
    a[idx]=-INF; a[nxt[idx]]=-INF;
    ll nnxt=nxt[nxt[idx]];
    nxt[pre[idx]]=nnxt;
    if(nnxt<n+2)pre[nnxt]=pre[idx];
    a[pre[idx]]=val;

    st.insert(P(a[pre[idx]],pre[idx]));
  }
  cout<<sum<<endl;

  return 0;
}
