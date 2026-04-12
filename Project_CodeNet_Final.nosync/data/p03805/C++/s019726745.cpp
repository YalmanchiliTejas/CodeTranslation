#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string key(int a, int b) {
  return to_string(a) + "-" + to_string(b);
}

bool find(set<string> &edges, int a, int b) {
  if (edges.count(key(a, b))) return true;
  if (edges.count(key(b, a))) return true;
  return false;
}

int main() {
  int N, M;
  cin >> N >> M;
  set<string> edges;
  vector<int> nodes(N);
  for (int i = 0; i < N; i++) {
    nodes.at(i) = i + 1;
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    edges.insert(key(a, b));
  }
  int path = 0;
  sort(nodes.begin(), nodes.end());
  do {
    int reached = 0;
    for (int i = 1; i < N; i++) {
      if (find(edges, nodes.at(i - 1), nodes.at(i))) reached++;
    }
    if (nodes.at(0) == 1 && reached+1 >= N) path++;
  } while (next_permutation(nodes.begin(), nodes.end()));
  cout << path << endl;
}
