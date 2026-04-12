#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define N 100010
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
ll n,m;
vector<P> g[N];
class dijkstra{
    public:
    ll d[N],w[N];
    void init(ll s){
        w[0]=1;
        for(int i=1;i<=n;i++){
            d[i]=1e17,w[i]=0;
        }
        priority_queue<PP,vector<PP>,greater<PP> > Q;
        Q.push(make_pair(0,make_pair(s,0)));
        while(!Q.empty()){
            ll x=Q.top().second.first,p=Q.top().second.second;
            ll cost=Q.top().first;
            Q.pop();
            if(d[x]<cost)continue;
            if(d[x]==cost){
                mad(w[x],w[p]);
                continue;
            }
            d[x]=cost,w[x]=w[p];
            for(auto y:g[x]){
                Q.push(make_pair(cost+y.second,make_pair(y.first,x)));
            }
        }
    }
};
ll s,t;
int main(){
  cin>>n>>m>>s>>t;
  for(int i=0;i<m;i++){
      ll a,b,c; cin>>a>>b>>c;
      g[a].push_back(make_pair(b,c));
      g[b].push_back(make_pair(a,c));
  }
  dijkstra S,T;
  S.init(s);
  T.init(t);
  ll ans=S.w[t]*S.w[t]%mod;
  for(int i=1;i<=n;i++){
      if(S.d[i]==T.d[i]&&S.d[i]+T.d[i]==S.d[t]){
          ll xy=S.w[i]*T.w[i]%mod;
          mad(ans,-xy*xy);
      }
      for(auto e:g[i]){
          int j=e.first,len=e.second;
          if(S.d[i]*2<S.d[t]&&T.d[j]*2<S.d[t]&&S.d[i]+len+T.d[j]==S.d[t]){
              ll xy=S.w[i]*T.w[j]%mod;
              mad(ans,-xy*xy);
          }
      }
  }
  if(ans<0)ans+=mod;
  cout<<ans<<endl;
  return 0;
}
