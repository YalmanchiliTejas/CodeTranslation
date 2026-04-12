#include <bits/stdc++.h>
using namespace std;

vector<int> checker1(int A, int B, vector<string> vec){
  vector<int> res(0);
  for (int i = 0; i < A; i++){
    int counter = 0;
    for (int j = 0; j < B; j++){
      if (vec.at(i).at(j) == '#')
        counter++;
    }
    if (counter != 0)
      res.push_back(i);
  }
  return res;
}
vector<int> checker2(int A, int B, vector<string> vec){
  vector<int> res(0);
  for (int i = 0; i < A; i++){
    int counter = 0;
    for (int j = 0; j < B; j++){
      if (vec.at(j).at(i) == '#')
        counter++;
    }
    if (counter != 0)
      res.push_back(i);
  }
  return res;
}
int main() {
  int H, W, a = 0;
  vector<int> row, column;
  cin >> H >> W;
  vector<string> vec(H);
  for (int i = 0; i < H; i++){
    cin >> vec.at(i);
  }
  row = checker1(H, W, vec);
  column = checker2(W, H, vec);
  for (double i = 0; i < row.size(); i++){
    for (double j = 0; j < column.size(); j++){
      cout << vec.at(row.at(i)).at(column.at(j));
      if (j == column.size() - 1)
        cout << endl;
    }
  }
}

