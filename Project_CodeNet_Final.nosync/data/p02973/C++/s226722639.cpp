#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <list>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


template <class Monoid>
class SegmentTree
{
public:
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid M1;
  int sz;
  vector<Monoid> seg;

  SegmentTree(int n,const Func fu, const Monoid &m1): F(fu) , M1(m1) {init(n);}
  void init(int n)
  {
      sz= 1;
      while (sz < n) sz *= 2;
      seg.assign(sz * 2, M1);
  }
  void update(int k,const Monoid &x)
  {
    k+=sz;
    seg[k]=x;
    while(k>>=1)
    {
      seg[k]=F(seg[k*2],seg[k*2+1]);
    }
  }
  Monoid query(int l,int r)
  {
    Monoid L=M1,R=M1;
    l+=sz;r+=sz;
    for(;l<r;l>>=1,r>>=1)
    {
      if(l&1)L=F(L,seg[l++]);
      if(r&1)R=F(seg[--r],R);
    }
    return F(L,R);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  vector<pair<ll,ll>>b(n);
  rep(i,n)b[i]={a[i],-i};
  map<ll,ll>ma;
  sort(all(b));

  ll id=1;
  rep(i,n){
    ma[(b[i].first<<32)-b[i].second]=id++;
  }
  auto check=[&](){
    SegmentTree<ll>st(id+1,[](ll a,ll b){return max(a,b);},0);
    rep(i,n){
      ll ta=ma[(a[i]<<32)+i];
      ll tmax=st.query(0,ta);
      if(tmax==0){
        st.update(ta,ta);
      }
      else {
        st.update(tmax,0);
        st.update(ta,ta);
      }
    }
    ll res=0;
    rep(i,id+1){
      if(st.query(i,i+1))res++;
    }
    return res;
  };
  cout<<check()<<endl;


  return 0;

}
