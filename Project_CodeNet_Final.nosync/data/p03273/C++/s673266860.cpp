#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> G(H);

  for(int i=0; i<H ; i++)
    cin >> G.at(i);

  //vector<vector<int>> P(H, vector<int>(0));
  set<int> W_mark;
  set<int> H_mark;

  for(int i=0; i<H; i++){
    for(int j=0; j<W ; j++){
      if(G.at(i).at(j) == '#'){
        W_mark.insert(j);
        H_mark.insert(i);
      }
    }
  }

  //cout << W_mark.find(0) << endl;

  for(int i=0; i<H ; i++){
    bool line = false;
    for(int j=0; j<W ; j++){
      if(H_mark.count(i) != 0 && W_mark.count(j) != 0){
        cout << G.at(i).at(j);
        line = true;
      }
    }
    if(line) cout << endl;
  }
}