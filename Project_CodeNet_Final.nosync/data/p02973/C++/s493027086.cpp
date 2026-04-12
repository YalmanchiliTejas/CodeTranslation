#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //e
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    auto itr = st.upper_bound(-a[i]);
    if (itr == st.end()) {
      st.insert(-a[i]);
      ans++;
    } else {
      st.erase(itr);
      st.insert(-a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}