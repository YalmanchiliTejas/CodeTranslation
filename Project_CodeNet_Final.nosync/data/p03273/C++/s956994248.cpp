#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w; cin>>h>>w;
  int mat1[h][w];
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      char c; cin>>c;
      if( c == '.') mat1[i][j] = 0;
      else mat1[i][j] = 1;
    }
  }
  for(int i=0; i<h; ++i){
    bool can_erase = true;
    for(int j=0; j<w; ++j){
      if( mat1[i][j]  == 1){
        can_erase = false; break;
      }
    }
    if( can_erase){
      for(int j=0; j<w; ++j){
        mat1[i][j] = 2;
      }
    }
  }
  for(int j=0; j<w; ++j){
    bool can_erase = true;
    for(int i=0; i<h; ++i){
      if( mat1[i][j]  == 1){
        can_erase = false; break;
      }
    }
    if( can_erase){
      for(int i=0; i<h; ++i){
        mat1[i][j] = 2;
      }
    }
  }
  for(int i=0; i<h; ++i){
    bool exit_enter = false;
    for(int j=0; j<w; ++j){
      if( mat1[i][j]  == 2) continue;
      else if( mat1[i][j] == 0){
        cout<<'.'; exit_enter = true;
      }
      else {
        cout<< '#'; exit_enter = true;
      }
    }
    if(exit_enter) cout<<endl;
  }
  return 0;
}
  
