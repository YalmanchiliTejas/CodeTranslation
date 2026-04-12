
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
#include <functional>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

#include <atcoder/convolution>
#include <atcoder/dsu>
#include <atcoder/fenwicktree>
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <atcoder/maxflow>
#include <atcoder/mincostflow>
#include <atcoder/modint>
#include <atcoder/scc>
#include <atcoder/segtree>
#include <atcoder/string>
#include <atcoder/twosat>

using namespace atcoder;
//typedef modint998244353 mint;

ll op(ll a,ll b){
  return max(a,b);
}

ll e(){
  return -1;
}

ll target;
bool f(ll a){
  return a<target;
}

int main(){
  int N,Q;
  cin>>N>>Q;
  VL A(N);
  rep(i,N) cin>>A[i];
  segtree<ll,op,e> seg(N);
  rep(i,N) seg.set(i,A[i]);
  while(Q--){
    ll T,B,C;
    cin>>T>>B>>C;
    if(T==1){
      seg.set(B-1,C);
    }else if(T==2){
      cout<<seg.prod(B-1,C)<<endl;
    }else{
      target=C;
      cout<<seg.max_right<f>(B-1)+1<<endl;
    }
  }
}