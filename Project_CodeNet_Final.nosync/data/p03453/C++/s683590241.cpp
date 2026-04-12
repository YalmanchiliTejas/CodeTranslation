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

#define INF 1e18
#define mod 1000000007

struct edge{
  ll f,t,c;
};

ll n,m,s,t;
ll d1[101010],cnt1[101010];
ll d2[101010],cnt2[101010];
vector<P> g[101010];
vector<edge> es;
bool used[101010];

int main(){
  cin>>n>>m>>s>>t;
  s--; t--;
	rep(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--; b--;
    g[a].push_back(P(b,c));
    g[b].push_back(P(a,c));
    es.push_back((edge){a,b,c});
  }
  {
    rep(i,n)d1[i]=INF;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    d1[s]=0;
    cnt1[s]=1;
    while(que.size()){
      ll nd=que.top().fi,v=que.top().se; que.pop();
      if(d1[v]<nd)continue;
      for(P e : g[v]){
        ll u=e.fi,c=e.se;
        if(d1[u]==nd+c){
          (cnt1[u]+=cnt1[v])%=mod;
        }else if(d1[u]>nd+c){
          d1[u]=nd+c;
          cnt1[u]=cnt1[v];
          que.push(P(nd+c,u));
        }
      }
    }
  }
  {
    rep(i,n)d2[i]=INF;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,t));
    d2[t]=0;
    cnt2[t]=1;
    while(que.size()){
      ll nd=que.top().fi,v=que.top().se; que.pop();
      if(d2[v]<nd)continue;
      for(P e : g[v]){
        ll u=e.fi,c=e.se;
        if(d2[u]==nd+c){
          (cnt2[u]+=cnt2[v])%=mod;
        }else if(d2[u]>nd+c){
          d2[u]=nd+c;
          cnt2[u]=cnt2[v];
          que.push(P(nd+c,u));
        }
      }
    }
  }
  ll tot=d1[t];
  ll res=cnt1[t]*cnt2[s]%mod;
  rep(i,n){
    if(d1[i]*2==tot){
      ll cnt=(cnt1[i]*cnt2[i])%mod;
      res=(res-((cnt*cnt)%mod)+mod)%mod;
      //dbg(i);
    }
  }
  rep(i,es.size()){
    ll u=es[i].f,v=es[i].t,c=es[i].c;
    if(d1[u]>d1[v])swap(u,v); // d1[u] < d1[v];
    if(d1[u]*2<tot&&tot<d1[v]*2&&d1[u]+d2[v]+c==tot){
      ll cnt=(cnt1[u]*cnt2[v])%mod;
      res=(res-((cnt*cnt)%mod)+mod)%mod;
      //dbg(u); dbg(v);
      //dbg(d1[u]); dbg(d1[v]); dbg(c);
      //dbg(res);
    }
  }
  cout<<res<<endl;
	return 0;
}
