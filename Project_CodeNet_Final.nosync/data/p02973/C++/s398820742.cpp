#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> st;
  rep(i, n) {
    cin >> a[i];
    auto it = st.lower_bound(a[i]);
    if (it != st.begin()) {
      it--;
      st.erase(it);
    }
    st.insert(a[i]);
  }
  cout << st.size() << endl;
}