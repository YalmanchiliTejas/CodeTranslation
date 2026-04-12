#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

bool isWhiteRow(int, vector<vector<char>>);
bool isWhiteCol(int, vector<vector<char>>);

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> table[i][j];
    }
  }
  
  vector<int> col(0); //列
  vector<int> row(0); //行
  
  for(int i = 0; i < H; i++) {
    if (!isWhiteRow(i, table))
      row.push_back(i);
  }
  for(int j = 0; j < W; j++) {
    if (!isWhiteCol(j, table))
      col.push_back(j);
  }
  
  for(int i = 0; i < row.size(); i++) {
    for(int j = 0; j < col.size(); j++) {
      cout << table[row[i]][col[j]];
    }
    cout << endl;
  }
}

bool isWhiteRow(int i, vector<vector<char>> table) {
  for(int j = 0; j < table[i].size(); j++) {
    if (table[i][j] != '.')
      return false;
  }
  return true;
}

bool isWhiteCol(int j, vector<vector<char>> table) {
  for(int i = 0; i < table.size(); i++) {
    if (table[i][j] != '.')
      return false;
  }
  return true;
}
