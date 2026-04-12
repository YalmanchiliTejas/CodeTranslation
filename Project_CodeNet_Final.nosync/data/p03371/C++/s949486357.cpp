#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans=5000*1e5+5000*1e5+1;
  
  int n=max(x, y)*2;
  int ai, bi, ci;
  rep(i, n+1){
    ai = bi = ci = 0;
    
    ci = i;
    (x-ci/2)>0 ? ai=x-ci/2 : ai=0;
    (y-ci/2)>0 ? bi=y-ci/2 : bi=0;
    ans = min(ans, a*ai+b*bi+c*ci);
  }
  cout << ans << endl;  
  return 0;
}
