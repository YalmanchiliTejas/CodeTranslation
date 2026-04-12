#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int> st;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) {
    auto itr = st.upper_bound(-a[i]);
    if(itr != st.end()) st.erase(itr);//eraseで全部消えない？
    st.insert(-a[i]);
  }
  cout << st.size() << endl;
}