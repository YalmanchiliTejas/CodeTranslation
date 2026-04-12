#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  vector<int> H_blanc(0);
  vector<int> W_blanc(0);
  for(int k=0; k<H; k++){
    int cH = 0;
    for(int l=0; l<W; l++){
      if(vec.at(k).at(l) == '.'){
        cH++;
      }
    }
    if(cH == W){
      H_blanc.push_back(k);
    }
  }
  
  for(int m=0; m<W; m++){
    int cW = 0;
    for(int n=0; n<H; n++){
      if(vec.at(n).at(m) == '.'){
        cW++;
      }
    }
    if(cW == H){
      W_blanc.push_back(m);
    }
  }
  
   int a = 0;
  
  for(int x=0; x<H; x++){
    if(H_blanc.size() != 0){
      if(x == H_blanc.at(a)){
        if(a < H_blanc.size()-1){
         a++;
        }
        continue;
      }
    }
    int b = 0;
    int y = 0;
   while(y<W){
      if(W_blanc.size() != 0){
        if(y == W_blanc.at(b)){
        y++;
         if(b < W_blanc.size()-1){
         b++;
         }
         continue;
        }
       }
      
    cout << vec.at(x).at(y);
    y++;
    }
    cout << endl;
  }
  
}