#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,o,n) for(int i=o;i<n;++i)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second
#define all(X) X.begin(), X.end()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  int n;
  ll a,b;
  cin>>n>>a>>b;
  vector<pll> vs[5];
  rep(i,n){
    ll t,x,y;
    cin>>t>>x>>y; --t;
    vs[t].eb(x,y);
  }
  sort(vs,vs+5,[](const vector<pll> &a,const vector<pll> &b){return a.size()<b.size();});
  map<ll,vector<ll>> ps{{0,{0}}},qs{{0,{0}}};
  
  rep(i,3) for(pll p:vs[i]) qs[p.X].pb(p.Y);
  for(pll p:vs[0])for(pll q:vs[1])for(pll r:vs[2]) qs[p.X+q.X+r.X].pb(p.Y+q.Y+r.Y);
  for(pll p:vs[0])for(pll q:vs[1]) qs[p.X+q.X].pb(p.Y+q.Y);
  for(pll p:vs[0])for(pll r:vs[2]) qs[p.X+r.X].pb(p.Y+r.Y);
  for(pll q:vs[1])for(pll r:vs[2]) qs[q.X+r.X].pb(q.Y+r.Y);
  for(auto &p:qs) sort(all(p.Y));
  
  reps(i,3,5) for(pll p:vs[i]) ps[p.X].pb(p.Y);
  for(pll p:vs[3])for(pll q:vs[4]) ps[p.X+q.X].pb(p.Y+q.Y);
  for(auto &p:ps) sort(all(p.Y));
  //rep(i,5){for(pll x:vs[i]) cout<<x.X<<","<<x.Y<<"  ";cout<<endl;}
  
  // for(auto p:ps){cout<<p.X<<":"; for(int y:p.Y) cout<<y<<",";cout<<endl;}
  // for(auto p:qs){cout<<p.X<<":"; for(int y:p.Y) cout<<y<<",";cout<<endl;}
  map<ll,ll> cnt;
  auto l=ps.rbegin(),r=l;
  for(auto &p:qs){
    for(;r!=ps.rend();++r){
      if(r->X < a-p.X) break;
      for(ll y:r->Y) ++cnt[y];
    }
    for(;l!=ps.rend();++l){
      if(l->X <= b-p.X) break;
      vector<ll> rm;
      for(ll y:l->Y) if(--cnt[y]==0) rm.pb(y);
      for(ll y:rm) cnt.erase(y);
    }
    // cout<<p.X<<endl;
    // for(pll x:cnt)cout<<x.X<<","<<x.Y<<"  ";cout<<endl;
    for(ll y:p.Y){
      auto it=cnt.lower_bound(a-y);
      if(it!=cnt.end() && it->X<=b-y){
	cout<<"Yes"<<endl;
	return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}