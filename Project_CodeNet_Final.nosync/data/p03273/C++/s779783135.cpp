#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> data(H);
  for (int i=0; i<H; i++) {
    cin >> data.at(i);
  }
  vector<string> data2;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data.at(i).at(j) == '#'){
        data2.push_back(data.at(i));
        break;
      }
    }
  }
  vector<int> B(W);
  for(int i=0;i<W;i++){
    for(int j=0;j<data2.size();j++){
      if(data2.at(j).at(i) == '#'){
        B.at(i) = 1;
        break;
      }
    }
  }
  for(int i=0;i<data2.size();i++){
    for(int j=0;j<W;j++){
      if(B.at(j) == 1){
        cout << data2.at(i).at(j);
      }
    }
    cout << endl;
  }
}