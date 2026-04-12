
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

vector<int> uf, usz;
int nc;

void init(int n){
  vector<int> uf_(n);
  vector<int> usz_(n, 1);
  uf = uf_;
  usz = usz_;
  nc = n;

  for(int i = 0; i < uf.size(); i++){
    uf[i] = i;
  }
}

int find(int a){
  return (uf[a] == a) ? a : uf[a] = find(uf[a]);
}

void union_(int a, int b){
  a = find(a);
  b = find(b);

  if(a != b){
    if(usz[a] >= usz[b]){
      swap(a, b);
    }
    uf[a] = b;
    usz[b] += usz[a];
    nc--;
  }
}

int check(int a, int b){
  return (find(a) == find(b)) ? 1 : 0;
}

int get_size(int a){
  return usz[find(a)];
}

int main() {
  ll n;
  cin>>n;
  init(n);
  vector<pair<pair<ll,ll>, ll> > v1;
  vector<pair<pair<ll,ll>, ll> > v2;
  vector<pair<ll, pair<ll,ll> > > v3;
  rep(i,0,n){
    ll a,b;
    cin>>a>>b;
    v1.pb(mp(mp(a,b),i));
    v2.pb(mp(mp(b,a),i));
  }
  sort(all(v1));
  sort(all(v2));
  rep(i,0,v1.sz-1){
    ll a1 = v1[i+1].fi.fi-v1[i].fi.fi;
    ll b1 = v1[i].se;
    ll c1 = v1[i+1].se;
    ll a2 = v2[i+1].fi.fi-v2[i].fi.fi;
    ll b2 = v2[i].se;
    ll c2 = v2[i+1].se;
    v3.pb(mp(a1,mp(b1,c1)));
    v3.pb(mp(a2,mp(b2,c2)));
  }
  sort(all(v3));
  ll ans = 0;
  rep(i,0,v3.sz){
    ll a3 = v3[i].fi;
    ll b3 = v3[i].se.fi;
    ll c3 = v3[i].se.se;
    if(check(b3,c3)==0){
      ans += a3;
      union_(b3,c3);
    }
  }
  cout << ans <<endl;
  return 0;
}