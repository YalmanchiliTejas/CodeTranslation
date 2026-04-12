#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> T(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> T.at(i).at(j);
    }
  }
  //１周目
  vector<vector<char>> Tre(W);
  //int K=0;
  for (int i=0; i < H; i++) {
    for (int j=0; j < W;j++) {
      if (T.at(i).at(j) == '#') {
        for (int jj=0; jj < W; jj++) {
          Tre.at(jj).push_back(T.at(i).at(jj));
        }
        break;
      }
    }  
    //if (j<W-1)
      //K++;
  } //i<Hについて終了
  
  //以下２周目
  vector<vector<char>> Trere(Tre.at(0).size());
  //int Kre=0;
  for (int i=0; i < W; i++) {
    for (int j=0; j < Tre.at(0).size();j++) {
      if (Tre.at(i).at(j) == '#') {
        for (int jj=0; jj < Tre.at(0).size(); jj++) {
          Trere.at(jj).push_back(Tre.at(i).at(jj));
        }
        break;
      }
    }  
    //if (j<K-1)
      //Kre++;
  
  } //i<Wについて終了
  
  //cout << Trere.size() << endl;
  //cout << Trere.at(0).size() << endl;
  //cout << Trere.at(0).at(0) << endl;
 //cout << Kre << endl;
  
  for (int i = 0; i < Trere.size(); i++) {
    for (int j = 0; j < Trere.at(0).size(); j++) {
      cout << Trere.at(i).at(j);
      if (j==Trere.at(0).size()-1)
        cout << endl;
    }
  } 
  
 
}