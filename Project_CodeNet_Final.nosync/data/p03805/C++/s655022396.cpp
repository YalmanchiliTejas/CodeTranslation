#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_M = 8;

typedef pair<int, int> P;
typedef pair<int, vector<bool> > PM;

int n, m;

int solve(vector<P> g) {
  int ans = 0;
  stack<PM> st;
  vector<bool> checked;
  for(int i = 0; i < n; i++) checked.push_back(false);
  checked[0] = true;
  st.push(make_pair(0, checked));

  while(!st.empty()) {
    PM pm = st.top();
    st.pop();

    bool isAll = true;
    for (int i = 0; i < n; i++) {
      if (!pm.second[i]) {
        isAll = false;
        break;
      }
    }

    if (isAll) {
      ans++;
      continue;
    }

    for (int i = 0; i < m; i++) {
      vector<bool> cp_checked1;
      if (g[i].first == pm.first && !pm.second[g[i].second]) {
        for(int i = 0; i < n; i++) cp_checked1.push_back(pm.second[i]);
        cp_checked1[g[i].second] = true;
        st.push(make_pair(g[i].second, cp_checked1));
      }

      vector<bool> cp_checked2;
      if (g[i].second == pm.first && !pm.second[g[i].first]) {
        for(int i = 0; i < n; i++) cp_checked2.push_back(pm.second[i]);
        cp_checked2[g[i].first] = true;
        st.push(make_pair(g[i].first, cp_checked2));
      }
    }
  }
  return ans;
}

int main() {
  cin >> n >> m;

  vector<P> g;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g.push_back(make_pair(a-1, b-1));
  }

  int ans = solve(g);
  cout << ans << "\n";
}
