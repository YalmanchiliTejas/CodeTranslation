/* おまじない　*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD=pow(10,9)+7;
const ll INF=(1LL<<62);
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
void init(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}


template< typename Monoid >
class SegmentTree {
public:
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

vector<ll> compress(vector<ll>v){
    ll N=v.size();
    vector<ll>copy;
    for(int i=0;i<N;i++){
        copy.push_back(v[i]);
    }
    sort(copy.begin(),copy.end());
    vector<ll>ret;
    for(int i=0;i<N;i++){
        ret.push_back(lower_bound(copy.begin(),copy.end(),v[i])-copy.begin());
    }
    return ret;
}

int main(){
    init();
    ll N;cin>>N;
    vector<ll>A(N);
    for(int i=0;i<N;i++)cin>>A[i];

    vector<ll>v=compress(A);
    ll ans=0;
    SegmentTree<ll>seg(N+10,[](ll a,ll b){return a+b;},0);
    for(int i=0;i<N;i++){
        //自分より左にあって自分より小さいものの個数
        ll num=seg.query(0,v[i]);
        //cout<<"num"<<num<<endl;
        if(num==0){
            //0個なら追加
            ans++;
            seg.update(v[i],seg[v[i]]+1);
        }else{
            //あるならその中で最大ものを使う
            ll right=v[i];
            ll left=0;
            while(right-left>1){
                ll mid=(right+left)/2;
                if(seg.query(0,mid+1)>=num)right=mid;
                else left=mid;
            }
            seg.update(right,seg[right]-1);
            //cout<<"right"<<right<<endl;
            seg.update(v[i],seg[v[i]]+1);
        }
    }
    cout<<ans<<endl;
}