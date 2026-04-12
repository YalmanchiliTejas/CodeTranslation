#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

int target = 0;

int e(){return -1;}
int op(int a,int b){return max(a,b);}
bool f(int n){return n < target;}

int main(){
  
  int n,Q;
  cin >> n >> Q;
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  segtree<int,op,e> seg(v);
  while(Q--){
    int t,l,r;cin >> t >> l >> r;
    if(t == 1){
      seg.set(--l,r);
    }else if(t == 2){
      cout << seg.prod(--l,r) << "\n";
    }else{
      target = r;
      cout << seg.max_right<f>(--l)+1 << "\n";

    }
  }

  


  return 0;
}