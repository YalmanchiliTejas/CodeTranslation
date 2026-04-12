#include<iostream>
#include<vector>
#include<atcoder/segtree>

using namespace std;
using namespace atcoder;

int64_t vi;
int64_t op(int64_t a,int64_t b){return a<b?b:a;}
int64_t e(){return -1;}
bool f(int64_t aj){return aj<vi;}

int32_t main(){
  int64_t n,q;
  cin>>n>>q;
  vector<int64_t> a(n);
  for(auto& ai:a)cin>>ai;
  
  using RMQ = segtree<int64_t,op,e>;
  RMQ seg(a);
  
  while(q--){
    int64_t t;cin>>t;
    if(t==1){
      int64_t x,v;cin>>x>>v;x--;
      seg.set(x,v);
    }
    if(t==2){
      int64_t l,r;cin>>l>>r;l--;r--;
      cout<<seg.prod(l,r+1)<<endl;
    }
    if(t==3){
      int64_t x;cin>>x>>vi;x--;
      int64_t res = seg.max_right<f>(x);
      cout<<res+1<<endl;
    }
  }
}
