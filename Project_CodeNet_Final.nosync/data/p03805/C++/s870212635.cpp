#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, M, i, j;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (i = 0; i < M; i++) {
    cin >> a.at(i) >> b.at(i);
  }
  vector<int> graph(N - 1);
  for (i = 0; i < N - 1; i++) {
    graph.at(i) = i + 2;
  }
  int count = 0;
  bool flag = false;
  do {
    for (i = -1; i < N - 2; i++) {
      flag = false;
      if (i == -1) {
        for (j = 0; j < M; j++) {
          if (a.at(j) == 1) {
            if (b.at(j) == graph.at(i + 1)) {
              flag = true;
              break;
            }
          }
        }
      }
      else {
        if (graph.at(i) < graph.at(i + 1)) {
          for (j = 0; j < M; j++) {
            if (a.at(j) == graph.at(i)) {
              if (b.at(j) == graph.at(i + 1)) {
                flag = true;
                break;
              }
            }
          }
        }
        else {
          for (j = 0; j < M; j++) {
            if (b.at(j) == graph.at(i)) {
              if (a.at(j) == graph.at(i + 1)) {
                flag = true;
                break;
              }
            }
          }
        }
      }
      if (!flag) {
        break;
      }
    }
    if (flag) {
      count++;
    }
  } while (next_permutation(graph.begin(), graph.end()));
  cout << count << endl;
}