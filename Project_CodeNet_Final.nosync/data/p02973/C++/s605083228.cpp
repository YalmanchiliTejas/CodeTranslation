#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n;

  multiset<int> st{-1};  // 見つからなかったら-INFが出てくる
  for (int i = 0; i < n; i++) {
    cin >> a;
    auto it = --st.lower_bound(a);
    if (*it != -1) st.erase(it);  // 使える色がある
    st.insert(a);
  }

  cout << st.size() - 1 << endl;
}
