//In The Name Of Allah
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define double long double 
#define fi first
#define se second
#define pii pair<int, int>

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    if (st.upper_bound(-a[i]) == st.end()) {
      st.insert(-a[i]);
    } else {
      auto it = st.upper_bound(-a[i]);
      st.erase(it);
      st.insert(-a[i]);
    }
  }
  cout << sz(st) << "\n";
}

