#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>>data(H, vector<char>(W));
  vector<int> judge(H, 0);
  vector<int> judge2(W, 0);
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> data.at(i).at(j);
      if(data.at(i).at(j) == '#'){       
        judge.at(i) = 1;
        judge2.at(j) = 1;
      }
    }
  }
  
  for(int i=0; i<H; i++){
    if(judge.at(i) == 1){
      for(int j=0; j<W; j++){
        if(judge2.at(j) == 1){
          cout << data.at(i).at(j);
        }
        if(j == W-1){
          cout << endl;
        }
      }
    }
  }
}
