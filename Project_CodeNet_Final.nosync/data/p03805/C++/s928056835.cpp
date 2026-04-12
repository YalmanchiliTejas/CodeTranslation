#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  
  int ans = 0;
  vector<int> v(N - 1);
  for (int i = 0; i < N - 1; ++i) v[i] = i + 1;
  do {
    bool judge = true;
    
    int memo = false;
    for (int x : graph[0]) {
      if (x == v[0]) memo = true;
    }
    if (!memo) judge = false;
    
    for (int j = 0; j < N - 2; ++j) {
      int meme = false;
      for (int x : graph[v[j]]) {
        if (x == v[j + 1]) meme = true;
      }
      if (!meme) judge = false;
    }
    
    if (judge) ++ans;
  } while (next_permutation(v.begin(), v.end()));
  
  cout << ans << endl;
  return 0;
}