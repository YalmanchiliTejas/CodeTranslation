#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

#include <functional>
#include <climits>

//SegmentTree<int> seg(N,[](int a,int b){return min(a,b);},INT_MAX);
template< typename T>
class SegmentTree{
private:
  void resize(int size){
      n=1;
      while(n<size) n*=2;
      tree.resize(2*n-1,def);
  }
public:

  using F = function<T(T,T)>;

  int n;
  vector<T> tree;
  F operation;
  T def;

  SegmentTree(){}
  SegmentTree(int size,F _operation,T _def):operation(_operation),def(_def){
    resize(size);
  }

  void embody(int size,F _operation,T _def){
    operation=_operation;
    def=_def;
    resize(size);
  }

  void initialize(const vector<T> &v){
    int size=v.size();
    resize(size);

    for(int i=0;i<size;i++) tree[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--) tree[i]=operation(tree[2*i+1],tree[2*i+2]);
  }

  void update(int index,T value){
    index+=n-1;

    tree[index]=value;
    while(index>0){
      index=(index-1)/2;
      tree[index]=operation(tree[2*index+1],tree[2*index+2]);
    }
  }

  T query(int a,int b,int k=0,int l=0,int r=-1){//[a,b)
    if(r<0) r=n;

    if(r<=a||b<=l) return def;
    else if(a<=l&&r<=b) return tree[k];
    else{
      T lval=query(a,b,2*k+1,l,(l+r)/2);
      T rval=query(a,b,2*k+2,(l+r)/2,r);
      return operation(lval,rval);
    }
  }

  T get(int index){
      return tree[index+n-1];
  }

  int find(int x,int k=0,int l=0,int r=-1){// a[0]+...+a[i]>=x (i:minimal)
    if(r<0) r=n;
    if(tree[k]<x) return -1;
    if(r-l==1) return k-(n-1);
    if(tree[2*k+1]>=x) return find(x,2*k+1,l,(l+r)/2);
    else return find(x-tree[2*k+1],2*k+2,(l+r)/2,r);
  }

  //right -> change vl to vr   (notice doesn't contain b. range [a,b))
  int find_left(int a,int b,T x,int k=0,int l=0,int r=-1){// max(a[a],...,a[i])>=x (i:minimal)
      if(r<0) r=n;
      if(tree[k]<x||r<=a||b<=l) return -1;
      if(r-l==1) return k-(n-1);
      int vl=find_left(a,b,x,2*k+1,l,(l+r)/2);
      if(vl>=0) return vl;
      return find_left(a,b,x,2*k+2,(l+r)/2,r);
  }
};

const ll INF=1e18;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,Q;
  cin>>N>>Q;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  SegmentTree<ll> seg(N,[](ll a,ll b){return max(a,b);},-INF);
  seg.initialize(A);
  rep(q,Q){
      int T;cin>>T;
      if(T==1){
          int X;ll V;
          cin>>X>>V;
          X--;
          seg.update(X,V);
      }else if(T==2){
          int L,R;
          cin>>L>>R;
          L--;R--;
          cout<<seg.query(L,R+1)<<"\n";
      }else{
          int X;ll V;
          cin>>X>>V;
          X--;
          int left=seg.find_left(X,N,V);
          if(left==-1) cout<<N+1<<"\n";
          else cout<<left+1<<"\n";
      }
  }

  return 0;
}
