// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  multiset<int> st;
  int ans = 0;
  // 証明できます，できるので
  for(int i = 0; i < n; i++) {
    auto ite = st.lower_bound(a[i]);
    if(ite != st.begin()) {
      st.erase(prev(ite));
    } else ans++;
    st.insert(a[i]);
  }
  cout << ans << endl;
  return 0;
}
