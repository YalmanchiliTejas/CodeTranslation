#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

struct LazySegTree {
  vector<ll> seg, lazy;
  int size;
  LazySegTree() {}
  LazySegTree(int n) {
    init(n);
  }
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    seg.resize(size * 2);
    lazy.resize(size * 2);
    for(int i = 0; i < size*2; i++)seg[i]=-INF;
  }
  void update(int k,ll v){
    k += size-1;
    seg[k] = v;
    while(k > 0){
      k = (k - 1)/2;
      seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void push(int k, int l, int r) {
    seg[k] += lazy[k];
    if (r - l > 1) {
      lazy[k * 2 + 1] += lazy[k];
      lazy[k * 2 + 2] += lazy[k];
    }
    lazy[k] = 0;
  }
  void add(int a, int b, ll v, int k, int l, int r) {
    push(k, l, r);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] += v;
      push(k, l, r);
    } else {
      add(a, b, v, k * 2 + 1, l, (l + r) / 2);
      add(a, b, v, k * 2 + 2, (l + r) / 2, r);
      seg[k] = max(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void add(int a, int b, ll v) {
    add(a, b, v, 0, 0, size);
  }
  ll query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if (r <= a || b <= l) return -INF*100; // caution
    if (a <= l && r <= b) return seg[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl,vr);
  }
  ll query(int a, int b) {
    return query(a, b, 0, 0, size);
  }
};

ll n,m;
ll l[200010],r[200010],a[200010];
vector<ll> ls[200010];
vector<P> rs[200010];
ll dp[200010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>m;
  rep(i,m){
    cin>>l[i]>>r[i]>>a[i];
    r[i]++;
    ls[l[i]].push_back(a[i]);
    rs[r[i]].push_back(P(l[i],a[i]));
  }
  LazySegTree sgt(n+2);
  rep(i,n+2)sgt.update(i,0);

  repl(i,1,n+2){
    for(ll v : ls[i]){
      sgt.add(0,i,v);
    }
    for(P p : rs[i]){
      sgt.add(0,p.fi,-p.se);
    }
    dp[i]=sgt.query(0,i);
    sgt.add(i,i+1,dp[i]);
  }
  cout<<dp[n+1]<<endl;

  return 0;
}
