#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

struct LazySegmentTree{
private:
  int N;
  vector<ll> node;
  vector<ll> lazy;
public:
  LazySegmentTree(vector<ll> v){
    int SZ=(int)v.size();
    N=1;
    while(N<SZ) N*=2;
    node.resize(2*N-1);
    lazy.resize(2*N-1,0);

    for(int i=0;i<SZ;i++) node.at(i+N-1)=v.at(i);
    for(int i=N-2;i>=0;i--) node.at(i)=max(node.at(2*i+1),node.at(2*i+2));
  }

  void eval(int k,int l,int r){
    if(lazy.at(k)==0) return;
    node.at(k)+=lazy.at(k);
    if(r-l>1){
      lazy.at(2*k+1)+=lazy.at(k);
      lazy.at(2*k+2)+=lazy.at(k);
    }
    lazy.at(k)=0;
  }

  void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
    if(r==-1) r=N;
    eval(k,l,r);
    if(r<=a || b<=l)  return;
    if(a<=l && r<=b){
      lazy.at(k)+=x;
      eval(k,l,r);
    }
    else{
      add(a,b,x,2*k+1,l,(l+r)/2);
      add(a,b,x,2*k+2,(l+r)/2,r);
      node.at(k)=max(node.at(2*k+1),node.at(2*k+2));
    }
  }

  ll getmax(int a,int b,int k=0,int l=0,int r=-1){
    if(r==-1) r=N;
    if(r<=a || b<=l)  return 0;
    eval(k,l,r);
    if(a<=l && r<=b)  return node.at(k);
    ll vl=getmax(a,b,2*k+1,l,(l+r)/2);
    ll vr=getmax(a,b,2*k+2,(l+r)/2,r);
    return max(vl,vr);
  }
};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,M;
  cin >> N >> M;
  vector<vector<pair<int,int>>> la(N+1);
  for(int i=0;i<M;i++){
    int l,r,a;
    cin >> l >> r >> a;
    la.at(r).pb(mp(l,a));
  }

  LazySegmentTree seg(vector<ll>(N+1,0));
  for(int i=1;i<N+1;i++){
    ll mx=seg.getmax(0,i);
    seg.add(i,i+1,mx);
    for(int j=0;j<sz(la.at(i));j++){
      int l=la.at(i).at(j).fi;
      int a=la.at(i).at(j).se;
      seg.add(l,i+1,a);
    }
  }
  cout << seg.getmax(0,N+1) << endl;

  return 0;
}