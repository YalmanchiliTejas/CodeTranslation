#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=10;
mat G(N);
ll n,m;

ll dfs(ll f,set<ll> al) {
  al.insert(f);
  ll res=0;
  if(al.size()==n) res=1;
  for(ll t:G[f]) {
    if(al.count(t)) continue;
    res+=dfs(t,al);
  }
  return res;
}

int main() {
  cin >> n >> m;
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;
    a--,b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  set<ll> al;
  ll ans=dfs(0,al);
  cout << ans << endl;
}