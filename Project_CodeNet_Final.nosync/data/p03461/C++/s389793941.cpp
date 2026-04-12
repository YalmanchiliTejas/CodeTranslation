#include <bits/stdc++.h>

using namespace std;

bool solve(int A, int B) {
  int dist[10][10];
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      cin >> dist[i][j];
    }
  }

  int T = 101;
  vector<vector<int>> data(T, vector<int>(T, -1));
  for (int x = 0; x < T; x++) {
    for (int y = 0; y < T; y++) {
      for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++) {
          int basecost = 0;
          basecost += (i + 1) * x;
          basecost += (j + 1) * y;
          int amari = dist[i][j] - basecost;
          data[x][y] = max(data[x][y], amari);
        }
    }
  }

  int cnt = 0;
  vector<vector<int>> ans(A, vector<int>(B, 200));
  for (int x = 0; x < T; x++)
    for (int y = 0; y < T; y++) {
      // cout << x << " " << y << " " << data[x][y] << endl;
      if (data[x][y] < 0) continue;
      cnt++;
      for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++) {
          int cost = (i + 1) * x + (j + 1) * y + data[x][y];
          ans[i][j] = min(ans[i][j], cost);
        }
    }
  for (int i = 0; i < A; i++)
    for (int j = 0; j < B; j++)
      if (ans[i][j] != dist[i][j]) return false;

  cout << "Possible" << endl;
  cout << 2 * T + 1 << " " << 2 * T + cnt << endl;
  for (int i = 0; i < T; i++) {
    cout << i + 1 << " " << i + 2 << " X" << endl;
  }
  for (int i = 0; i < T; i++) {
    cout << i + T + 1 << " " << i + T + 2 << " Y" << endl;
  }
  int s = 1;
  int t = T + T + 1;

  for (int x = 0; x < T; x++) {
    for (int y = 0; y < T; y++) {
      if (data[x][y] < 0) continue;
      cout << s + x << " " << t - y << " " << data[x][y] << endl;
    }
  }
  cout << s << " " << t << endl;
  return true;
}
int main() {
  int A, B;
  cin >> A >> B;
  bool ok = solve(A, B);
  if (!ok) {
    cout << "Impossible" << endl;
  }

  return 0;
}