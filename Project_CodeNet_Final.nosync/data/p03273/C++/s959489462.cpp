#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, b, c, d, f;
  c = 0, d = 0, f = 0;
  cin >> N >> M;
  vector<vector<char>> a(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a.at(i).at(j);
    }
  }
  for (int i = 0; i < N; i++) {
    b = 0;
    for (int j = 0; j < M; j++) {
      if (a.at(i).at(j) == '#') {
        b = 1;
      }
    }
    if (b == 0) {
      for (int j = 0; j < M; j++) {
        a.at(i).at(j) = '1';
      }
      c++;
    }
  }
  for (int i = 0; i < M; i++) {
    b = 0;
    for (int j = 0; j < N; j++) {
      if (a.at(j).at(i) == '#') {
        b = 1;
      }
    }
    if (b == 0) {
      for (int j = 0; j < N; j++) {
        a.at(j).at(i) = '1';
      }
      d++;
    }
  }
  vector<vector<char>> e(N - c);
  for (int i = 0; i < N; i++) {
    b = 0;
    for (int j = 0; j < M; j++) {
      if (a.at(i).at(j) == '#') {
        b = 1;
      }
    }
    if (b == 0) {
      f++; 
    }
    for (int j = 0; j < M; j++) {
      if (a.at(i).at(j) != '1') {
        e.at(i - f).push_back(a.at(i).at(j));
      }
    }
  }
  for (int i = 0; i < N - c; i++) {
    for (int j = 0; j < M - d; j++) {
      cout << e.at(i).at(j);
    }
    cout << endl;
  }
}