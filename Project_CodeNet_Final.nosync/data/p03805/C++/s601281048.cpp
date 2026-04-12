#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int a[100], b[100];

bool exists(vector<int> v) {
  for (int i = 0; i < v.size() - 1; i++) {
    int s = v[i], e = v[i+1];
    bool flag = false;
    for (int j = 0; !flag && j < M; j++) {
      if ((a[j] == s && b[j] == e) || (b[j] == s && a[j] == e)) { flag = true; }
    }
    if (!flag) { return false; }
  }
  return true;
}

void solve() {
  vector<int> v;
  for (int i = 1; i <= N; i++) { v.push_back(i); }

  int ans = 0;
  do {
    if (v[0] != 1) { continue; }
    if (exists(v)) { ans++; }
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
  }
  solve();
}