#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N, vector<int>(0));
  for (int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    graph.at(a-1).emplace_back(b-1);
    graph.at(b-1).emplace_back(a-1);
  }
  vector<int> path(N-1);
  int count = 0;
  for (int i=1; i<N; i++) path.at(i-1) = i;
  do {
    for (int i=0; i<N-1; i++) {
      bool flag = false;
      if (i == 0) {
        for (auto link : graph.at(0)) {
          if (link == path.at(i)) {
            flag = true;
            break;
          }
        }
      }
      else {
        for (auto link : graph.at(path.at(i-1))) {
          if (link == path.at(i)) {
            flag = true;
            break;
          }
        }
      }
      if (!flag) break;
      if (i == N-2) count++;
    }
  } while (next_permutation(path.begin(), path.end()));
  cout << count << endl;
}