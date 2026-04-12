#include <iostream>
using namespace std;
int n, out = 0, x[8][8] = {}, f[8] = {};
void search(int s, int c) {
  if (c == n) {
    out++;
    return;
  }
  for (int i = 1; i < n; i++) {
    if (x[s][i] == 1 && f[i] == 0) {
      f[i] = 1;
      search(i, c + 1);
      f[i] = 0;
    }
  }
  return;
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    x[a - 1][b - 1] = 1;
    x[b - 1][a - 1] = 1;
  }
  search(0, 1);
  cout << out << endl;
  return 0;
}
