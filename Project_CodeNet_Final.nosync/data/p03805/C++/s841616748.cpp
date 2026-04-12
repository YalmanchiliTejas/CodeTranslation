#include "bits/stdc++.h"
using namespace std;
using ll = long long; using ull = unsigned long long;
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(ll i = (ll)(n)-1;i >= 0;--i)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define eb(val) emplace_back(val)
const double PI = acos(-1);
const double EPS = 1e-10;
const ll MOD = 1e9+7;
//#define int ll
void cioacc(){//accelerate cin/cout
  cin.tie(0);
  ios::sync_with_stdio(false);
}
vb used;
int solve(vvi &gr,int n,int a=0,int c=1){
  if(c==n) return 1;
  int res = 0;
  for(auto i:gr[a]){
    if(used[i]) continue;
    used[i] = true;
    res += solve(gr,n,i,c+1);
    used[i] = false;
  }
  return res;
}
signed main(){
  int n,m;
  cin >> n >> m;
  used.assign(n,false);
  vvi gr(n);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    --a; --b;
    gr.at(a).emplace_back(b);
    gr.at(b).emplace_back(a);    
  }
  used[0] = true;
  cout << solve(gr,n) << endl;
}

