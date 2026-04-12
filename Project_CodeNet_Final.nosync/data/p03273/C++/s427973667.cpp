#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,flag=0,A=0,B=0;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> vec[i][j];
    }
  }
  for(int k=0;k<H;k++){
    for(int l=0;l<W;l++){
      if(vec[k][l]=='#'){
        A=1;
      }
      if(l==W-1&&A==0){
        for(int m=0;m<W;m++){
          vec[k][m]='0';
        }
      }
    }
    A=0;
  }
  for(int n=0;n<W;n++){
    for(int o=0;o<H;o++){
      if(vec[o][n]=='#'){
        B=1;
      }
      if(o==H-1&&B==0){
        for(int p=0;p<H;p++){
          vec[p][n]='0';
        }
      }
    }
    B=0;
  }
  for(int q=0;q<H;q++){
    for(int r=0;r<W;r++){
      if(vec[q][r]!='0'){
        cout << vec[q][r];
        flag=1;
      }
      if(r==W-1){
        if(flag){
          flag=0;
          cout << endl;
        }
      }
    }
  }
}