#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

ll par[100010],ranki[100010]; 

void init(int n){
  fr(i,n){
    par[i]=i;
    ranki[i]=0;
  }
}

int find(int x){
  if(par[x]==x) return x;
  else return par[x]=find(par[x]);
}
 
void unit(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ranki[x]<ranki[y]) par[x]=y;
  else par[y]=x;
  if(ranki[x]==ranki[y]) ranki[x]++;
}
 
bool same(int x,int y){
  return find(x)==find(y);
}

struct edge{
  ll dm,cd,ct;
  bool operator<(const edge& right) const{
    return ct<right.ct;
  }
};
vector<edge> edges;

int main(){
  ll n,x,y;
  vector<pair<P,ll>> px,py;
  cin>>n;
  fr(i,n){
    cin>>x>>y;
    px.pb(mp(mp(x,y),i));
    py.pb(mp(mp(y,x),i));
  }
  sort(px.begin(),px.end());
  sort(py.begin(),py.end());
  fr(i,n-1){
    edges.pb((edge){px[i].sd,px[i+1].sd,min(abs(px[i].ft.ft-px[i+1].ft.ft),abs(px[i].ft.sd-px[i+1].ft.sd))});
    edges.pb((edge){py[i].sd,py[i+1].sd,min(abs(py[i].ft.ft-py[i+1].ft.ft),abs(py[i].ft.sd-py[i+1].ft.sd))});
  }
  init(n);
  ll ans=0,cnt=0;
  sort(edges.begin(),edges.end());
  for(auto it=edges.begin();cnt<n-1;it++){
    edge e=*it;
    if(same(e.dm,e.cd)) continue;
    unit(e.dm,e.cd);
    ans+=e.ct;
    cnt++;
  }
  cout<<ans<<endl;
}