#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const string ln = "\n";
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  set<char> st;
  for (int i = 0; i < 3; i++) {
    st.insert(s[i]);
  }

  string ans = "No";
  if (st.size() == 2) {
    ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}