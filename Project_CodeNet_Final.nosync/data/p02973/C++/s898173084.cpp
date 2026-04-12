#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  multiset<int> st;
  st.insert(-1);
  st.insert(1e9 + 7);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    auto temp = st.lower_bound(A[i]);
    temp--;
    if (*temp != -1) {
      st.insert(A[i]);
      st.erase(temp);
    } else {
      ans++;
      st.insert(A[i]);
    }
  }

  cout << ans << endl;
  return 0;
}