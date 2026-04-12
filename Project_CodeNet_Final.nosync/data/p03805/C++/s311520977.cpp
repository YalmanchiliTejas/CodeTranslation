#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> Mat(n, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    Mat[a][b] = Mat[b][a] = 1;
  }

  vector<int> data(n - 1);
  for (int i = 0; i < n - 1; i++) {
    data[i] = i + 1;
  }

  int cnt = 0;
  do {
    bool is_ok = true;
    if (Mat[0][data[0]] == -1) {
      is_ok = false;
    }
    for (int i = 1; i < n - 1; i++) {
      int u = data[i - 1];
      int v = data[i];
      if (Mat[u][v] == -1) {
        is_ok = false;
      }
    }
    if (is_ok) {
      cnt++;
    }
  } while (next_permutation(data.begin(), data.end()));

  cout << cnt << endl;

  return 0;
}