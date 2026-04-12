#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<int> G[8];

int f(int x, int b) {
  if (b == (1<<N)-1) return 1;
  int s = 0;
  for (int t : G[x]) {
    if (b & (1<<t)) continue;
    s += f(t, b | (1<<t));
  }
  return s;
}

int main() {
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout << f(0, 1) << "\n";
  return 0;
}
