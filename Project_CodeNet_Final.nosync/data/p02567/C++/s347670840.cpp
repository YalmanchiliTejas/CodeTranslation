#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
using namespace atcoder;

int op(int a, int b){
  return max(a, b);
}

int e(){
  return -1;
}

int ta;
bool comp(int x){
  return x < ta;
}

int main(){
  int n, q;
  cin >> n >> q;
  segtree<int, op, e> seg(n);
  rep(i, n){
    int in;
    cin >> in;
    seg.set(i, in);
  }
rep(_q, q){
  int t, a, b;
  cin >> t >> a >> b;
  if(t == 1) seg.set(a-1, b);
  else if(t == 2) cout << seg.prod(a-1, b) << endl;
  else{
    ta = b;
    a--;
    cout << seg.max_right<comp>(a) + 1 << endl;
  }
}
  return 0;
}