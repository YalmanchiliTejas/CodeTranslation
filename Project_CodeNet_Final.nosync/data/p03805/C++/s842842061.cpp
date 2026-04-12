#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

using edge_t = pair<int, int>;

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  set<edge_t> st;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    st.emplace(u, v);
    st.emplace(v, u);
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    a[i] = i;

  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i)
      if (st.find(edge_t(a[i], a[i + 1])) == st.end())
        ok = false;

    if (ok)
      ++ans;
  } while (next_permutation(a.begin() + 1, a.end()));

  cout << ans << endl;

  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}
