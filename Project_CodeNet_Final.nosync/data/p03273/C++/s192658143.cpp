#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> a(H,vector<char>(W));
  for(int i=0; i<H; i++){
   for(int j=0; j<W; j++){
     cin >> a[i][j];
   }
  }
  
  int count=0;
  
  for(int i=0; i<H; i++){
    int row=0;
   for(int j=0; j<W; j++){
     if(a[i][j]=='.') row++;
   }
   if(row==W){
     count++;
    for(int j=0; j<W; j++){
     a[i][j]=0; 
    }
   }
  }
  
  for(int j=0; j<W; j++){
    int ver=0;
   for(int i=0; i<H; i++){
     if(a[i][j]=='.') ver++;
   }
   if(ver==H-count){
    for(int i=0; i<H; i++){
     a[i][j]=0; 
    }
   }
  }
  
  bool dele=false;
  
  for(int i=0; i<H; i++){
   for(int j=0; j<W; j++){
     if(a[i][j]=='.' || a[i][j]=='#'){
      cout << a[i][j];
       dele = true;
     }
   }
    if(dele==true) cout << endl;
  }
  
  
  
}