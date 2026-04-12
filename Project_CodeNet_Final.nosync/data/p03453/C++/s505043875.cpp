#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint pow(ll t) const { if (!t) return 1; mint a = pow(t>>1); a *= a; if (t&1) a *= *this; return a; }
    // for prime mod
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
};

typedef vector<vector<pair<ll,int>>> wgraph;
typedef pair<ll,int> pli;


vector<pair<ll,mint>> bfs(wgraph v,int x){
  priority_queue<pli,vector<pli>,greater<pli>> q;
  vector<pair<ll,mint>> dist(v.size(),{longinf,0});
  dist[x]={0,1};
  q.push({0LL,x});

  while(q.size()){
    pli p=q.top(); q.pop();
    ll d=p.F, cur=p.S;
    if(dist[cur].F<d){ continue; }
    for(auto to:v[cur]){
      if(dist[to.S].F>dist[cur].F+to.F){
        dist[to.S].F = dist[cur].F+to.F;
        dist[to.S].S = dist[cur].S;
        q.push({dist[to.S].F, to.S});
      } else if(dist[to.S].F == dist[cur].F+to.F){
        dist[to.S].S += dist[cur].S;
      }
    }
  }
  return dist;
}

int main(){
  int n,m,s,t;
  cin >> n >> m >> s >> t; s--; t--;
  wgraph v(n);
  rep(i,m){
    int x,y,z;
    cin >> x >> y >> z; x--; y--;
    v[x].emplace_back(z,y);
    v[y].emplace_back(z,x);
  }
  vector<pair<ll,mint>> ds=bfs(v,s); //<length, routs num>
  vector<pair<ll,mint>> dt=bfs(v,t);
  mint ans = ds[t].S*dt[s].S;
  ll minlength = ds[t].F;
  rep(i,n){		//meet at node
    if(ds[i].F==dt[i].F && 2*ds[i].F == minlength){
      mint tmp = ds[i].S * dt[i].S;
      ans -= tmp*tmp;
    }
  }
  rep(i,n){		//meet on edge
    for(auto to:v[i]){
      int j = to.S;
      if(ds[i].F+to.F+dt[j].F == minlength && 2*ds[i].F<minlength && 2*dt[j].F<minlength){
        mint tmp = ds[i].S*dt[j].S;
        ans -= tmp*tmp;
      }
    }
  }
  cout << ans.x << endl;
  return 0;
}
