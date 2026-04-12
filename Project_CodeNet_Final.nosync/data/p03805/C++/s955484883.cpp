#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

bool Graph[10][10];

int main() {
  int N,M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Graph[a][b] = true;
    Graph[b][a] = true;
  }
  int x[N];
  for (int i = 0; i < N; i++) {
    x[i] = i;
  }
  int ans = 0;
  do {
    bool can = true;
    if (x[0] != 0) {
      can = false;
    }
    for (int i = 1; i < N; i++) {
      if (Graph[x[i-1]][x[i]] == false) {
        can = false;
      }
    }
    if (can) ans++;
} while(next_permutation(x,x+N));
cout << ans << endl;
  return 0;
}