#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

void printArray(vector<int> a) {
  for (auto x : a) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    num[i] = i;
  }
  Graph G(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  // for (int i = 0; i < n; i++) {
  //   printArray(G[i]);
  // }
  int count = 0;

  do {
    if (num[0] != 0) {
      break;
    }

    for (int i = 0; i < n - 1; i++) {
      int temp = num[i];
      if (find(G[temp].begin(), G[temp].end(), num[i + 1]) != G[temp].end()) {
        // cout << i << endl;
        if (i == n - 2) {
          // printArray(num);
          count++;
        }
      } else {
        break;
      }
    }
  } while (next_permutation(num.begin(), num.end()));

  cout << count << endl;
}