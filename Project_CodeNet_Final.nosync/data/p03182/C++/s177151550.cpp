#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll NEUT = -1e18, MAXN = 2e5+10;
ll tree[4*MAXN], lazy[4*MAXN], dp[MAXN];

ll op(ll a, ll b){
  return max(a,b);
}

void unlazy(int node, int start, int end){
  tree[node] += lazy[node];
  if(start != end){
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int l, int r, ll val, int node = 1, int start = 1, int end = MAXN){
  if(lazy[node]) unlazy(node, start, end);
  if(start > end || start > r || end < l) return;
  if(l <= start && end <= r){
    tree[node] += val;
    if(start != end) lazy[2*node] += val, lazy[2*node+1] += val;
    return;
  }
  int mid = (start + end) / 2;
  update(l, r, val, 2*node, start, mid);
  update(l, r, val, 2*node + 1, mid + 1, end);
  tree[node] = op(tree[2*node], tree[2*node+1]);
}

ll query(int l, int r, int node = 1, int start = 1, int end = MAXN){
  if(start > end || start > r || end < l) return NEUT;
  if(lazy[node]) unlazy(node, start, end);
  if(l <= start && end <= r) return tree[node];
  int mid = (start + end) / 2;
  return op(query(l, r, 2*node, start, mid), query(l, r, 2*node + 1, mid + 1, end));
}

vector<ii> g[MAXN];

int main(){FIN;
  int n,m,l,r,v; cin >> n >>m;
  fore(i,0,m) cin >> l >> r >> v, g[l].pb({r,v});
  for(int i = n; i >= 0; i--){
    dp[i] = query(i+1,n+1);
    update(i+1,i+1,dp[i]);
    for(auto x : g[i]) update(i+1, x.fst+1, x.snd);
  }
  cout << dp[0] << endl;
}