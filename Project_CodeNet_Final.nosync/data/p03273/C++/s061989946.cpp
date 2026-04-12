#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >>H >>W;
 
  vector<vector<char>> V(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> V.at(i).at(j);
    }
  }

  vector<int> HR(H);
  vector<int> WR(W);
  
  for (int i=0; i<H; i++){
    int A=0;
    for(int j=0; j<W; j++){
      if(V.at(i).at(j) == '#'){
        A++;
        break;
      } 
    }
    if(A == 0){
      HR.at(i) =1;
    }
  }
  
  for (int i=0; i<W; i++){
    int A=0;
    for(int j=0; j<H; j++){
      if(V.at(j).at(i) == '#'){
        A++;
        break;
      } 
    }
    if(A == 0){
      WR.at(i) = 1;
    }
  }
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(HR.at(i) == 1){
        break;
      }
      else if(WR.at(j) == 1){
        continue;
      }
      cout << V.at(i).at(j);
    }
   if(HR.at(i) != 1){
     cout << endl;
   }
  }

}