#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int input() {
  int cell;
  cin >> cell;
  return cell;
}

vector<vector<char>> inputs(int H, int W) {
  vector<vector<char>> table(H, vector<char>(W));
  rep(i, H){
    rep(j, W){
      cin >> table.at(i).at(j);
    }
  }
  return table;
}

vector<int> row_check(vector<vector<char>> table){
  int H = table.size();
  int W = table.at(0).size();
  vector<char> check_line(W, '.');
  vector<int> indexs(0);
  rep(i, H){
    if(table.at(i) == check_line)
      indexs.push_back(i);
  }
  return indexs;
}

vector<vector<char>> tenchi(vector<vector<char>> table){
  int H = table.size();
  int W = table.at(0).size();
  vector<vector<char>> tenchied(W, vector<char>(H));
  rep(i, H){
    rep(j, W){
      tenchied.at(j).at(i) = table.at(i).at(j);
    }
  }
  return tenchied;
}

vector<vector<char>> mark_white_line(vector<vector<char>> table, vector<int> row_indexs, vector<int> column_indexs){
  int H = table.size();
  int W = table.at(0).size();
  //消すlineを'%'で埋める
  rep(i, W){
    for(int row_index : row_indexs){
      table.at(row_index).at(i) = '%';
    }
  }
  rep(i, H){
    for(int column_index : column_indexs){
      table.at(i).at(column_index) = '%';
    }
  }
  return table;
}

vector<char> delete_white_line(vector<vector<char>> table){
  vector<char> line_table(0);
  for(vector<char> row : table){
    for(char cell : row){
      if(cell == '%')
        continue;
      line_table.push_back(cell);
    }
  }
  return line_table;
}

void output(vector<char>, int, int);

int main() {
  int H, W;
  H = input();
  W = input();
  vector<vector<char>> table = inputs(H, W);
  vector<int> row_indexs = row_check(table);
  vector<int> column_indexs = row_check(tenchi(table));
  vector<char> line_table = delete_white_line(mark_white_line(table, row_indexs, column_indexs));
  output(line_table, H-row_indexs.size(), W-column_indexs.size());
}

void output(vector<char> line_table, int H, int W){
  rep(i, H){
    rep(j, W){
      cout << line_table.at(W*i+j);
    }
    cout << endl;
  }
}