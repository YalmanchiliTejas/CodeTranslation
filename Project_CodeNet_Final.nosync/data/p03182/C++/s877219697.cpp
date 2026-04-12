#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

#define mkp make_pair
const ll INF=-1e16;

class LazySegmentTree{
private:
  int n;
  vector<ll> node,lazy;
  vector<bool> lazyFlag;

public:
  LazySegmentTree(vector<ll> v){
      n=1;
      while(n<v.size()) n*=2;
      node.resize(2*n-1,INF);
      lazy.resize(2*n-1,0);
      lazyFlag.resize(2*n-1,false);
      
      for(int i=0;i<v.size();i++) node[i+n-1]=v[i];
      for(int i=n-2;i>=0;i--) node[i]=max(node[2*i+1],node[2*i+2]);
  }

  void eval(int k,int l,int r){
      if(lazyFlag[k]){
          node[k]+=lazy[k];
          if(r-l>1){
              lazyFlag[2*k+1]=true;
              lazyFlag[2*k+2]=true;
              lazy[2*k+1]+=lazy[k];
              lazy[2*k+2]+=lazy[k];
          }
          lazy[k]=0;
          lazyFlag[k]=false;
      }
  }

  void update(int a,int b,ll x,int k=0,int l=0,int r=-1){
      if(r<0) r=n;
      eval(k,l,r);
      if(b<=l||r<=a) return;
      if(a<=l&&r<=b){
          lazy[k]=x;
          lazyFlag[k]=true;
          eval(k,l,r);
      }else{
          update(a,b,x,2*k+1,l,(r+l)/2);
          update(a,b,x,2*k+2,(r+l)/2,r);
          node[k]=max(node[2*k+1],node[2*k+2]);
      }
  }

  ll getMax(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0) r=n;
      eval(k,l,r);
      if(b<=l||r<=a) return INF;
      if(a<=l&&r<=b) return node[k];

      ll vl,vr;
      vl=getMax(a,b,2*k+1,l,(l+r)/2);
      vr=getMax(a,b,2*k+2,(l+r)/2,r);
      return max(vl,vr);
  }

  void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
      if(r<0) r=n;
      eval(k,l,r);
      if(b<=l||r<=a) return;
      if(a<=l&&r<=b){
          lazy[k]+=x;
          lazyFlag[k]=true;
          eval(k,l,r);
      }else{
          add(a,b,x,2*k+1,l,(r+l)/2);
          add(a,b,x,2*k+2,(r+l)/2,r);
          node[k]=max(node[2*k+1],node[2*k+2]);
      }
  }
};

int N,M;
vector<int> L,R;
vector<ll> A;

vector<pair<int,ll>> ed[200020];

int main(){
  cin>>N>>M;
  L.resize(M);
  R.resize(M);
  A.resize(M);
  for(int i=0;i<M;i++) cin>>L[i]>>R[i]>>A[i];

  for(int i=0;i<M;i++) ed[R[i]].push_back(mkp(L[i],A[i]));

  LazySegmentTree seg(vector<ll>(N+1,0));
  for(int i=1;i<=N;i++){
    ll ma=seg.getMax(0,i);
    seg.add(i,i+1,ma);
    for(auto a:ed[i]){
      ll l,c;
      tie(l,c)=a;
      seg.add(l,i+1,c);
    }
  }

  cout<<seg.getMax(0,N+1)<<endl;

  return 0;
}
