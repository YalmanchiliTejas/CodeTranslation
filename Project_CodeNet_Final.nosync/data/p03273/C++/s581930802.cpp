#include <bits/stdc++.h>
using namespace std;

int main() {
  //declare table(tab)
  int h, w;
  cin >> h >> w;
  vector<vector<char>> tab(h, vector<char>(w));
  //input
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++){
      cin >> tab.at(i).at(j);
    }
  }
  //mark rows which ISN'T filled with '.'
  vector<int> mark(0);
  for (int k = 0; k < h; k++){
    int count = 0;
    
    for (int l = 0; l < w; l++){
      if (tab.at(k).at(l) == '#'){
        count++;
      }
    }
    
    if (count != 0){
      mark.push_back(k);
    }
  }
  // do the same action with the row and the column switched
  vector<int> wark(0);
  for (int k = 0; k < w; k++){
    int count = 0;
    
    for (int l = 0; l < h; l++){
      if (tab.at(l).at(k) == '#'){
        count++;
      }
    }
    
    if (count != 0){
      wark.push_back(k);
    }
  }
  /***
  // for debug
  for (int m=0;m<mark.size();m++) cout<< mark.at(m);
  cout<< endl;
  for (int n=0;n<wark.size();n++) cout<< wark.at(n);
  cout<< endl;
  ***/
  // output the table
  //範囲for文は()内の変数に配列の中身が入ってしまうので今回のような場合は使えないことに注意
  for (int m = 0; m < mark.size(); m++){
    for (int n = 0; n < wark.size(); n++){
      cout << tab.at(mark.at(m)).at(wark.at(n));
    }
    cout << endl;
  }
}