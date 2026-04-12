#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll INF=1e9+7;
const ll inf=INF*INF;
const ll MOD=998244353;
const ll mod=MOD;
const int MAX=200010;

template< typename Monoid >
struct SegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
  }
 
  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x)
  {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b)
  {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const
  {
    return seg[k + sz];
  }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,q;cin>>n>>q;
    SegmentTree<ll> seg(n,[](ll a,ll b){return max(a,b);},-INF);
    rep(i,n){
        ll a;cin>>a;
        seg.set(i,a);
    }
    seg.build();
	while(q--){
        ll t;cin>>t;
        if(t==1){
            ll x,v;cin>>x>>v;
			x--;
			seg.update(x,v);
        }else if(t==2){
            ll l,r;cin>>l>>r;
			l--;
            ll ans=seg.query(l,r);
            cout<<ans<<endl;
        }else{
            ll x,v;cin>>x>>v;
			x--;
            ll d=seg.query(x,n);
            if(v>d){
                cout<<n+1<<endl;
            }else{
                ll l=x,r=n;
                while(r-l>1){
                    ll mid=(r+l)/2;
                    d=seg.query(x,mid);
                    if(v<=d)r=mid;
                    else l=mid;
                }
                cout<<r<<endl;
            }
        }
    }
}