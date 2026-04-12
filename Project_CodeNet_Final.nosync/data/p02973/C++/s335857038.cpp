#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  multiset<int> st;
  for(int i = 0; i < n; i++){
    auto it = st.lower_bound(a[i]);
    if(it != st.begin()){
      it--;
      st.erase(it);
    }
    st.insert(a[i]);
  }
  cout << st.size() << endl;

  return 0;
}
