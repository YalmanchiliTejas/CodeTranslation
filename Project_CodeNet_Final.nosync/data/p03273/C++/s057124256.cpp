#include <bits/stdc++.h>
using namespace std;

int main(void){
  int h,w,dame=0;
  cin >> h >> w;
  int delh[h]={},delw[w]={};
  string s[h];
  for(int i=0;i<h;i++){
      cin >> s[i];
      for(int j=0;j<w;j++){
          if(s[i][j]=='#'){
              dame++;
              break;
          }
      }
      if(dame==0){
          delh[i]++;
      }
      dame=0;
  }
  for(int j=0;j<w;j++){
      for(int i=0;i<h;i++){
          if(s[i][j]=='#'){
              dame++;
              break;
          }
      }
      if(dame==0){
          delw[j]++;
      }
      dame=0;
  }
  for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
          if(delh[i]==0&&delw[j]==0){
              cout << s[i][j];
          }
      }
      if(delh[i]==0)      cout << endl;
  }
}