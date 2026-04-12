#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> data1(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data1.at(i).at(j);
    }
  }
  
  vector<vector<char>> data2;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (data1.at(i).at(j) == '#') {
        data2.push_back(data1.at(i));
        break;
      }
    }
  }
  
  vector<vector<char>> data3(w, vector<char>(data2.size()));
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < data2.size(); j++) {
      data3.at(i).at(j) = data2.at(j).at(i);
    }
  }
  
  
  vector<vector<char>> data4;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < data2.size(); j++) {
      if (data3.at(i).at(j) == '#') {
        data4.push_back(data3.at(i));
        break;
      }
    }
  }
    
  vector<vector<char>> data5(data2.size(), vector<char>(data4.size()));
  for (int i = 0; i < data2.size(); i++) {
    for (int j = 0; j < data4.size(); j++) {
      data5.at(i).at(j) = data4.at(j).at(i);
    }
  }
  for (int i = 0; i < data2.size(); i++) {
    for (int j = 0; j < data4.size(); j++) {
      cout << data5.at(i).at(j);
      if (j == data4.size() - 1)
        cout << endl;
    }
  }
  
}