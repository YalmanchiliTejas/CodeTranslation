#include <bits/stdc++.h>
using namespace std;

int main() {
 int H,W;
  cin >> H >> W;
  vector<vector<char>>vec(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  vector<vector<char>>vecT(W,vector<char>(H));
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
     vecT.at(i).at(j)=vec.at(j).at(i);
    }
  }
  
  vector<vector<char>>vecH(H,vector<char>(W,'.'));
  vector<vector<char>>vecW(W,vector<char>(H,'.'));
  //これであっとるんか？//
  int numH;
  vector<int>pushH(numH);
  int numW;
  vector<int>pushW(numW);
  
  
  
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
     //pushHやpushWの中の数字と同じときtrueにしたい
      
      if(vec.at(i) == vecH.at(i)){
        
       continue; 
      }
       else if(vecT.at(j) == vecW.at(j)){
         if (j ==W-1){
          cout <<endl; 
           continue;
         }
         else{
          continue; 
         }
      }
      if (j == W-1){
       cout <<vec.at(i).at(j)<<  endl; 
      }
      else{
      cout << vec.at(i).at(j);
      }
      
      
    }
  }        
          
}
