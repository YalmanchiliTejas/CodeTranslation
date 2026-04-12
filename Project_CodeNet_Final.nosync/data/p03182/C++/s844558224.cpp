#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
#else
#define debug(x) ;
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

/* Starry Sky Tree */
//0-index

struct StarrySkyTree{
  typedef ll Type;
  int segn2;
  vector<Type> data, s_data;
  function<Type(Type, Type)> merge;

  StarrySkyTree(function<Type(Type, Type)> merge, int n): merge(merge)
  {
    for(segn2=1; segn2<n; segn2*=2);
    data.assign(segn2*2, 0);
    s_data.assign(segn2*2, 0);
  }

  StarrySkyTree(int n): //Original Ver.
    StarrySkyTree([](Type a, Type b){ return min(a, b); }, n) {}

  //get value of [a,b)
  Type query(int a, int b, int l = 0, int r = -1, int k = 0){
    if(r == -1) r = segn2;
    if(r <= a || b <= l) return LLINF; //大きさに注意
    if(a <= l && r <= b) return data[k] + s_data[k];
    return merge(query(a, b, l, (l+r)/2, k*2+1), query(a, b, (l+r)/2 , r, k*2+2)) + s_data[k];
  }

  //add x to [a,b)
  Type add(int a, int b, Type x, int l = 0, int r = -1, int k = 0){
    if(r == -1) r = segn2;
    if(a <= l && r <= b)
      s_data[k] += x;
    else if(a < r && l < b)
      data[k] = merge(add(a, b, x, l, (l+r)/2, k*2+1), add(a, b, x, (l+r)/2, r, k*2+2));

    return data[k] + s_data[k];
  }
};

int main(){
  int n, m;
  vector<pair<int,int> > vec[SIZE];
  ll sum = 0;

  scanf("%d%d", &n, &m);

  for(int i=0;i<m;i++){
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    l--; r--;
    vec[r].push_back({l,a});
    sum += a;
  }

  debug(n+2);
  StarrySkyTree seg(n+2);

  ll ans = 0;

  for(int i=0;i<n;i++){
    for(auto p : vec[i]){
      seg.add(0, p.first+1, p.second);
    }

    auto res = seg.query(0, i+2);
    ans = min(ans, res);
    seg.add(i+2, i+3, res);
  }

  for(int i=0;i<=n;i++){
    debug(i);
    debug(seg.query(i, i+1));
  }

  debug(ans);
  cout << max(0LL, sum - ans) << endl;

  return 0;
}
