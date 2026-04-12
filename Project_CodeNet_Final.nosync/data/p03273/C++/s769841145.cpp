#include<bits/stdc++.h>

using namespace std;
char mas[102][102];
int main(){
  int h,w;
  cin >> h >> w;
  for(int i=0;i!=h;i++){
    for(int j=0;j!=w;j++){
      cin >> mas[i][j];
    }
  }
  for(int i=0;i!=h;i++){
    int tmp=0;
    int tmp1=0;
    for(int j=0;j!=w;j++){
      tmp1++;
      if(mas[i][j]=='.'){
        tmp++;
      }
    }
    if(tmp1==tmp){
      for(int j=0;j!=w;j++){
        mas[i][j]='h';
      }
    }
  }
  for(int j=0;j!=w;j++){
    int tmp=0;
    int tmp1=0;
    for(int i=0;i!=h;i++){
      tmp1++;
      if(mas[i][j]=='.'||mas[i][j]=='h'){
        tmp++;
      }
    }
    if(tmp1==tmp){
      for(int i=0;i!=h;i++){
        mas[i][j]='h';
      }
    }
  }
  bool ansok;
  for(int i=0;i!=h;i++){
    for(int j=0;j!=w;j++){
      if(mas[i][j]!='h'){
        ansok=true;
        cout << mas[i][j];
      }
    }
    if(ansok==true){
      cout << endl;
      ansok=false;
    }
  }
}
