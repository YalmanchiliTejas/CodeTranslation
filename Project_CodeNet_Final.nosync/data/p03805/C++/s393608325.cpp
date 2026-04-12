#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  bool edge[n][n];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      edge[i][j] = false;
    }
  }
  for (int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    --a;
    --b;
    edge[a][b] = true;
    edge[b][a] = true;
  }
  int order[n-1];
  for (int i=0; i<n-1; i++) order[i] = i+1;
  int cnt = 0;
  do {
    int prev = 0;
    bool ok = true;
    for (int idx: order) {
      if (!edge[prev][idx]) {
        ok = false;
        break;
      }
      prev = idx;
    }
    if (ok) {
      ++cnt;
    }
  } while (next_permutation(order, order + n - 1));
  cout<<cnt<<endl;
}