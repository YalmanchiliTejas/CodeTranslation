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

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

template<class monoid>
struct LazySegmentTree
{
  using F=function<monoid(monoid,monoid)>;
private:
    int n;
    vector<ll> node, lazy;
    F f;
    monoid m1;


public:
    LazySegmentTree(int sz,F fun,monoid m1):f(fun),m1(m1)
    {
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1,m1);
        lazy.resize(2*n-1, 0);
    }
    void eval(int k, int l, int r)
    {
      if(lazy[k] != 0)
      {
        node[k] += lazy[k];//ここ
        if(r - l > 1)
        {
          lazy[2*k+1] += lazy[k];//ここ
          lazy[2*k+2] += lazy[k];//ここ
        }
        lazy[k] = 0;
      }
    }

    void add(int a, int b, monoid x, int k=0, int l=0, int r=-1)
    {
      if(r < 0) r = n;
      eval(k, l, r);
      if(b <= l || r <= a) return;
      if(a <= l && r <= b)
      {
          lazy[k] += x;//ここ
          eval(k, l, r);
      }
      else
      {
          add(a, b, x, 2*k+1, l, (l+r)/2);
          add(a, b, x, 2*k+2, (l+r)/2, r);
          node[k] = f(node[2*k+1],node[2*k+2]);
      }
    }

    monoid query(int a, int b, int k=0, int l=0, int r=-1)
    {
      if(r < 0) r = n;
      if(b <= l || r <= a) return 0;
      eval(k, l, r);
      if(a <= l && r <= b) return node[k];
      monoid vl = query(a, b, 2*k+1, l, (l+r)/2);
      monoid vr = query(a, b, 2*k+2, (l+r)/2, r);
      return f(vl,vr);
    }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vector<pair<int,int>>>sec(n+1);
  rep(i,m)
  {
    ll l,r,a;
    cin>>l>>r>>a;
    sec[r].push_back({l,a});
  }
  LazySegmentTree<ll> st(n+1,[](ll a,ll b){return max(a,b);},0);
  repi(i,1,n+1)
  {
    st.add(i,i+1,st.query(0,i));
    for(auto p:sec[i])
    {
      st.add(p.first,i+1,p.second);
    }
  }
  cout<<st.query(0,n+1)<<endl;


  return 0;

}
