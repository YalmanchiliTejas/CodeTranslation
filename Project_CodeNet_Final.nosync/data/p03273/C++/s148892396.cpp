#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int H, W;
  int sum = 0;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W, '.'));
  //配列に代入
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
    cin >>  grid.at(i).at(j); 
      
    }
  }
    
    //行成分の判別
  for(int i = 0; i < H; i ++){
    for(int j = 0, sum = 0; j < W; j++){
      
     //成分が「.」ならsumに＋１
      if(grid.at(i).at(j) == '.' ){
        sum += 1;
      }
      if(sum == W){
         for(int k = 0; k < W; k++){
           grid.at(i).at(k) = ' ';
           
        }
      }
    }
  }
  
  
	//列成分の判別
   for(int i = 0; i < W ; i++){
    for(int j = 0, sum = 0; j < H ; j++){
      
     //成分が「.」か空白ならsumに＋１
     if(grid.at(j).at(i) == '.'){
       sum += 1;
     }
      else if(grid.at(j).at(i) == ' '){
         sum += 1;
      }
      //列成分がすべて「.」なら空白を代入
      if(sum == H){
        for(int k = 0; k < H; k++){
         grid.at(k).at(i) = ' '; 
        }
      }
    }
  }
  
  //出力
 for(int i = 0;i < H ; i ++){
   for(int j = 0, sum =0; j < W; j++){
     //空白なら飛ばす
     if(grid.at(i).at(j) == ' '){
       sum += 1;
       if(j == W -1 && sum != W){
      cout << endl;
    }
     continue;
    }
      cout << grid.at(i).at(j);
     //最後の列になったら改行
       if(j == W -1 && sum != W){
      cout << endl;
    }
   }
 }
}