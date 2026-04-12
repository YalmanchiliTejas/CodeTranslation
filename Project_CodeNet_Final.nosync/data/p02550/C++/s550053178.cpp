#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N, X, M; cin >> N >> X >> M;
  vector<int> a = {X};
  map<int,int> m; m[X]++;
  
  int x = X;
  int k = 0;
  while(true) {
    x *= x;
    x %= M;
    if(x == 0) {
      int ans = 0;
      rep(i, a.size()) ans += a[i];
      cout << ans << endl;
      return 0;
    }
    if(m[x] > 0) {
      rep(i, a.size()) if(x == a[i]) k=i;
      break;
    }
    else {
      m[x]++;
      a.push_back(x);
    }
  }
  
  int ans = 0;
  rep(i, k) {
    ans += a[i];
    N--;
  }
  vector<int> b(a.size()-k);
  copy(a.begin()+k, a.end(), b.begin());
  int s = b.size();
  rep(i, s) ans += b[i]*(N/s);
  rep(i, N%s) ans += b[i];
  
  cout << ans << endl;
}
