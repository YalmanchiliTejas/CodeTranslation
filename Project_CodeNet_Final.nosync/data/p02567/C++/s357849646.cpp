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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  vector<int64_t> a(n);
  for(auto& ai:a)cin>>ai;
  
  using RMQ = segtree<int64_t,op,e>;
  RMQ seg(a);
  
  while(q--){
    int t;cin>>t;
    if(t==1){
      int x,v;cin>>x>>v;x--;
      seg.set(x,v);
    }
    if(t==2){
      int l,r;cin>>l>>r;l--;r--;
      cout<<seg.prod(l,r+1)<<'\n';
    }
    if(t==3){
      int x;cin>>x>>vi;x--;
      int res = seg.max_right<f>(x);
      cout<<res+1<<'\n';
    }
  }
}
