#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

signed main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  multiset<int> s;
  s.insert(a[0]);

  for(int i=1; i<n; i++) {
    auto lb = s.lower_bound(a[i]);
    if(lb == s.begin()) {
      s.insert(a[i]);
    }
    else {
      s.erase(prev(lb));
      s.insert(a[i]);
    }
  }
  cout << s.size() << endl;
}
