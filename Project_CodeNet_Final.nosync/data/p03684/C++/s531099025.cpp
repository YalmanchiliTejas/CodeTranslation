#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int par[100010];
int depth[100010];
void init(int n){
  for(int i=0;i<=n;i++){
      par[i]=i;
      depth[i]=0;
  }
}
int root(int x){
  return par[x]==x?x:par[x]=root(par[x]);
}
bool same(int x,int y){
  return root(x)==root(y);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x==y)return;
  if(depth[x]<depth[y]){
      par[x]=y;
  }else{
      par[y]=x;
      if(depth[x]==depth[y])depth[x]++;
  }
}
int main(){
    ll n;cin>>n;
    vector<pair<ll,pll> >es(0);
    vector<pair<pll,ll> >p(n);
    rep(i,n){
        ll x,y;cin>>x>>y;
        p[i]=(make_pair(make_pair(x,y),i));
    }
    sort(all(p));
    rep(i,n-1){
        es.pb(mp(p[i+1].first.first-p[i].first.first,mp(p[i].second,p[i+1].second)));
    }
    rep(i,n){
        swap(p[i].first.first,p[i].first.second);
    }
    sort(all(p));
    rep(i,n-1){
        es.pb(mp(p[i+1].first.first-p[i].first.first,mp(p[i].second,p[i+1].second)));
    }
    init(n-1);
    sort(all(es));
    ll cnt=0;
    rep(i,es.size()){
        if(!same(es[i].second.first,es[i].second.second)){
            unite(es[i].second.first,es[i].second.second);
            cnt+=es[i].first;
        }
    }
    cout<<cnt<<endl;
}