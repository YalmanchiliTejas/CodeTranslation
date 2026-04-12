#include <bits/stdc++.h>

// namespace std {
// template <> class hash<pair<int, int>> {
// public:
//   size_t operator()(const pair<int, int> &x) const {
//     return hash<int>()(x.first) ^ hash<int>()(x.second);
//   }
// };
// } // namespace std

using namespace std;

int traverse(int source, unordered_set<int> passed, vector<vector<int>> *edges) {
  if (passed.size() == edges->size()) {
    return 1;
  }
  int sum=0;
  for (auto dest: edges->at(source)) {
    if (passed.find(dest)!=passed.end()) {
      continue;
    }
    unordered_set<int> new_passed;
    new_passed = passed;
    new_passed.insert(dest);
    sum += traverse(dest, new_passed, edges);
  }
  return sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  // unordered_set<pair<int, int>> passed;
  unordered_set<int> passed;
  vector<vector<int>> edges(n, vector<int>(0));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges.at(a - 1).push_back(b - 1);
    edges.at(b - 1).push_back(a - 1);
  }
  passed.insert(0);
  cout << traverse(0, passed, &edges) << endl;
  return 0;
}