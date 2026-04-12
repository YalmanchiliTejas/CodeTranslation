#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  vector<vector<char>> list(N, vector<char>(M));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> list.at(i).at(j);
    }
  }
  
  vector<bool> one(N, false);
  vector<bool> two(M, false);
  
  int size_1 = list.size();
  int size_2 = list.at(0).size();
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (list.at(i).at(j) == '#') {
        one.at(i) = true;
        two.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < size_1; i++) {
    if (!one.at(i)) continue;
    for (int j = 0; j < size_2; j++) {
      if (!two.at(j)) continue;
      cout << list.at(i).at(j);
    }
    cout << endl;
  }
}