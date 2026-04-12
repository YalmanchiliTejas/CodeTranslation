#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
struct Node {
  ll x, y;
  Node() = default;
  Node(int a, int b) : x(a), y(b) {}
  friend bool operator<(const Node& n1, const Node& n2) {
    if (n1.x != n2.x) return n1.x < n2.x;
    return n1.y < n2.y;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  vector<Node> v(N);
 
  int vmin = INT_MAX;
  int imin = -1;
  int vmax = INT_MIN;
  int imax = -1;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    v[i].x = x;
    v[i].y = y;
  }
 
  sort(v.begin(), v.end());
 
  for (int i = 0; i < N; ++i) {
    int x = v[i].x;
    int y = v[i].y;
    if (vmin > x) {
      vmin = x;
      imin = i;
    }
 
    if (vmax < y) {
      vmax = y;
      imax = i;
    }
  }
 
  ll ret = 1LL << 62;
  const ll rmin = vmin;
  // if bmax = vmax;
  ll bmax = vmax;
 
  ll rmax = rmin;
  ll bmin = bmax;
 
  for (auto& n : v) {
    rmax = max(rmax, n.x);
    bmin = min(bmin, n.y);
  }
 
  ret = min(ret, (rmax - rmin) * (bmax - bmin));
  // if rmax = vmax;
  rmax = vmax;
 
  multiset<int> st;
  vector<Node> bv;
  for (int i = 0; i < N; ++i) {
    if (i != imin && i != imax) {
      bv.push_back(v[i]);
      st.insert(v[i].x);
    }
  }
  st.insert(v[imin].y);
  st.insert(v[imax].x);
 
  bmin = *st.begin();
  bmax = *st.rbegin();
  ret = min(ret, (rmax - rmin) * (bmax - bmin));
  for (int i = 0; i < bv.size(); ++i) {
    auto const& c = bv[i];
    // if (c.x > *st.begin()) break;
    st.erase(st.find(c.x));
    st.insert(c.y);
    bmin = *st.begin();
    bmax = *st.rbegin();
 
    ret = min(ret, (rmax - rmin) * (bmax - bmin));
  }
 
  cout << ret << endl;
}