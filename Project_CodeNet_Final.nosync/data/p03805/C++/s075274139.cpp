//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int p[8][8];
vl a;

ll bfs(vl a){
  ll k=a.size();
  if(a[0]!=0){
    return 0;
  }
  rep(i,k-1){
    if(p[a[i]][a[i+1]]==0){
      return 0;
    }
  }
  return 1;
}

int main() {
  ll n,m;
  cin >> n >> m;
  a.resize(n);
  rep(i,n){
    a[i]=i;
  }
  rep(i,n){
    rep(j,n){
      p[i][j]=0;
    }
  }
  rep(i,m){
    ll x,y;
    cin >> x >> y;
    x--;y--;
    p[x][y]=1;
    p[y][x]=1;
  }
  ll ans=bfs(a);
  while(next_permutation(a.begin(),a.end())){
    if(bfs(a)){
      ans++;
    }
  }
  cout << ans << endl;
}