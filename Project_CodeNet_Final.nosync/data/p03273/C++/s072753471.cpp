#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

template <typename T>
string join(const vector<T>& v, const char* delim = 0) {
  string s;
  if (!v.empty()) {
    s += v[0];
    for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
      if (delim) s += delim;
      s += v[i];
    }
  }
  return s;
}

template <typename T>
vector<vector<T>> transpose(vector<vector<T>>& v) {
  int row = v.size();
  int col = v[0].size();
  vector<vector<T>> trans(col, vector<T>(row));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      trans[j][i] = v[i][j];
    }
  }
  return trans;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  string row_string = string(W, '.');
  vector<int> row_to_delete(0);
  string joined_string;
  // row
  for (int i = 0; i < H; i++) {
    vector<char> row = a[i];
    joined_string = join(row);
    if (joined_string == row_string) {
      row_to_delete.push_back(i);
    }
  }
  int size_row_to_delete = row_to_delete.size();
  for (int i = 0; i < size_row_to_delete; i++) {
    a.erase(a.begin() + row_to_delete[i]);
    int n = 0;
    for_each(row_to_delete.begin(), row_to_delete.end(),
             [n](int& x) mutable { x -= 1; });
  }
  // col
  string col_string = string(a.size(), '.');
  vector<vector<char>> transposed = transpose(a);
  vector<int> col_to_delete(0);
  for (int i = 0; i < W; i++) {
    vector<char> col = transposed[i];
    joined_string = join(col);
    if (joined_string == col_string) {
      col_to_delete.push_back(i);
    }
  }
  int size_col_to_delete = col_to_delete.size();
  for (int i = 0; i < size_col_to_delete; i++) {
    transposed.erase(transposed.begin() + col_to_delete[i]);
    int n = 0;
    for_each(col_to_delete.begin(), col_to_delete.end(),
             [n](int& x) mutable { x -= 1; });
  }
  vector<vector<char>> output = transpose(transposed);
  for (vector<char> row : output) {
    cout << join(row) << endl;
  }
  return 0;
}