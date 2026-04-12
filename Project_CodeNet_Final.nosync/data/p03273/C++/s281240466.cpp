#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  char c;
  vector<int> t(N, 0);
  vector<vector<char>> table(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      table.at(i).at(j) = c;
    }
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (table.at(i).at(j) == '.') {
        count++;
      }
    }
    if (count == M) {
      t.at(i) = 1;
      for (int j = 0; j < M; j++) {
        table.at(i).at(j) = ' ';
      }
    }
    count = 0;
  }
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      if (table.at(i).at(j) == '.' || table.at(i).at(j) == ' ') {
        count++;
      }
    }
    if (count == N) {
      for (int i = 0; i< N; i++) {
        table.at(i).at(j) = ' ';
      }
    }
    count = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (table.at(i).at(j) != ' ') {
        cout << table.at(i).at(j);
      }
      if (j == M-1 && t.at(i) == 0) {
        cout << endl;
      }
    }
  }
}
