#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  vector<string> data(0);
  string empty = "";
  for (int i = 0; i < w; i++) {
    empty += ".";
  }

  for (int i = 0; i < h; i++) {
    string input; cin >> input;
    if (input != empty) {
      data.push_back(input);
    }
  }
  
  vector<int> delete_idx_list(0);
  for (int j = 0; j < w; j++) {
    int cnt = 0;
    for (int i = 0; i < data.size(); i++) {
      cnt += (data.at(i).at(j) == '.');
    }
    if (cnt == data.size()) {
      delete_idx_list.push_back(j);
    }
  }
  
  reverse(delete_idx_list.begin(), delete_idx_list.end());

  for (int k = 0; k < delete_idx_list.size(); k++) {
    int delete_idx = delete_idx_list.at(k);
    for (int i = 0; i < data.size(); i++) {
      data.at(i).erase(delete_idx, 1);
    }
  }
  
  for (int i = 0; i < data.size(); i++) {
    cout << data.at(i) << endl;
  } 
}