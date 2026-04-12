#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

int main(void) {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  int cnt = 0;
  multiset<int> st;

  for(int i=0; i<n; i++) {
    auto it = st.upper_bound(-a[i]);

    if(it == st.end()) {
      cnt++;
    }else{
      st.erase(it);
    }
    st.insert(-a[i]);

  }

  cout << cnt << endl;

  return 0;
}

// EOF
