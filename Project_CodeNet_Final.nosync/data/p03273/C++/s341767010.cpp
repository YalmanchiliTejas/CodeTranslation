#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
  
  int flag;
  vector<int> h_vec;
  for (int i=0; i<H; i++) {
    flag = 0;
    for (int j=0; j<W; j++) {
      cin >> data.at(i).at(j);
      if (data.at(i).at(j) == '#') flag = 1;
    }
    if (flag == 1) h_vec.push_back(i);
  }

  vector<int> w_vec;
  for (int j=0; j<W; j++) {
    flag = 0;
    for (int i : h_vec) {
      if (data.at(i).at(j) == '#') flag = 1;
    }
    if (flag == 1) w_vec.push_back(j);
  }
  
  for (auto i = h_vec.begin(); i != h_vec.end(); i++) {
    for (auto j = w_vec.begin(); j != w_vec.end(); j++) {
      cout << data.at(*i).at(*j);
    }
    cout << endl;
  }
}