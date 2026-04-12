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
#define bcnt __builtin_popcount

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
    for(int i = 0; i < size*2; i++)seg[i]=INF;
  }
  void update(int k,ll v){
    k += size-1;
    seg[k] = v;
    while(k > 0){
      k = (k - 1)/2;
      seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]);
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
      seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }
  void add(int a, int b, ll v) {
    add(a, b, v, 0, 0, size);
  }
  ll query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if (r <= a || b <= l) return INF*100; // caution
    if (a <= l && r <= b) return seg[k];
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl,vr);
  }
  ll query(int a, int b) {
    return query(a, b, 0, 0, size);
  }
};

int N,Q;
string s;
set<int> ngidx;
int a[300010],sum[300010];
LazySegTree sgt;

int main(){
  cin>>N>>Q;
  cin>>s;
  rep(i,N){
    if(s[i]=='('){
      sum[i+1]=sum[i]+1;
      a[i]=1;
    }
    if(s[i]==')'){
      ngidx.insert(i);
      sum[i+1]=sum[i]-1;
      a[i]=-1;
    }
  }
  sgt.init(N+1);
  rep(i,N+1)sgt.update(i,sum[i]);

  while(Q--){
    int q;
    cin>>q;
    q--;
    if(a[q]==1){
      a[q]=-1;
      ngidx.insert(q);
      sgt.add(q+1,N+1,-2);
      int res=*ngidx.begin();
      ngidx.erase(ngidx.begin());
      a[res]=1;
      sgt.add(res+1,N+1,+2);
      cout<<res+1<<endl;
    }else if(a[q]==-1){
      a[q]=1;
      ngidx.erase(q);
      sgt.add(q+1,N+1,+2);
      int lb=-1,ub=q+1;
      while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(sgt.query(mid,q+1)>=2)ub=mid;
        else lb=mid;
      }
      int res=ub-1;
      a[res]=-1;
      ngidx.insert(res);
      sgt.add(res+1,N+1,-2);
      cout<<res+1<<endl;
    }
  }

  return 0;
}

