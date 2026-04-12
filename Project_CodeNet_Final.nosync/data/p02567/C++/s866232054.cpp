#include<iostream>
#include<vector>

template<class T,class F>
struct segment_tree{
  std::vector<T> data;
  int n;F f;T identity;
  segment_tree(){}
  segment_tree(int sz,T ide,F _f):f(_f),identity(ide){
    n=1;while(n<sz)n<<=1;
    data.resize(2*n,identity);
  }
  segment_tree(std::vector<T> const& v,T ide,F _f):f(_f),identity(ide){
    build(v);
  }
  void build(std::vector<T> const& v){
    int sz=v.size();
    n=1;while(n<sz)n<<=1;
    data.resize(2*n,identity);
    for(int i=0;i<sz;++i)data[i+n]=v[i];
    for(int i=n-1;i>0;--i)data[i]=f(data[i<<1|0],data[i<<1|1]);
  }
  void set(int i,T x){
    i+=n;data[i]=x;
    while(i,i>>=1)data[i]=f(data[i<<1|0],data[i<<1|1]);
  }
  T fold(int l,int r)const{
    l+=n,r+=n;
    T x=identity;
    while(l<r){
      if(l&1)x=f(x,data[l++]);
      if(r&1)x=f(x,data[--r]);
      l>>=1,r>>=1;
    }
    return x;
  }
  T operator[](int i)const{return data[i+n];}
};
template<class T,class F>
auto make_segtree(int n,T ide,F f){
  return segment_tree<T,F>(n,ide,f);
}
template<class T,class F>
auto make_segtree(std::vector<T>const& v,T ide,F f){
  return segment_tree<T,F>(v,ide,f);
}

int main(){
  using namespace std;
  using ll = int64_t;
  cin.tie(0);
  ios::sync_with_stdio(false);
  constexpr char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<ll> a(n);
  for(auto& ai:a)cin>>ai;

  auto seg = make_segtree<ll>(a,0,[](ll a,ll b){return a<b?b:a;});
  while(q--){
    int t;cin>>t;
    if(t==1){
      int x,v;cin>>x>>v;x--;
      seg.set(x,v);
    }
    if(t==2){
      int l,r;cin>>l>>r;l--;r--;
      cout<<seg.fold(l,r+1)<<newl;
    }
    if(t==3){
      int x,v;cin>>x>>v;x--;
      int l=x,r=n+1;
      while(r-l>1){
        int m = l+r>>1;
        if(seg.fold(x,m)>=v)r=m;
        else l=m;
      }
      cout<<r<<newl;
    }
  }

}