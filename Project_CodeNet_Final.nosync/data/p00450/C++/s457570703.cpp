#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<int> cum(n + 1, 0);
    stack<int> st;
    st.push(1);
    for (int i = 2; i <= n; i++) {
      if (a[i] == a[i - 1]) continue;
      if (i & 1) {
        st.push(i);
      } else {
        int v;
        if (st.empty()) {
          v = 1;
        } else {
          v = st.top();
          st.pop();
        }
        cum[v - 1]--, cum[i - 1]++;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      cum[i] += cum[i + 1];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (a[i] + cum[i]) % 2 == 0;
    }

    cout << ans << endl;
  }

  return 0;
}
