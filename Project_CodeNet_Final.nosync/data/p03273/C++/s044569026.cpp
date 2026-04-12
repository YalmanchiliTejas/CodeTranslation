#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  char s[100][100];
  cin>>h>>w;
  for(int i=0;i<h;++i)
    for(int j=0;j<w;++j)
      cin>>s[i][j];
  
  for(int i=0;i<w;++i){
    for(int j=0;j<h;++j){
      if(s[j][i]=='#')
        break;
      if(j==h-1){
        for(int k=0;k<h;++k)s[k][i]='0';
      }
    }
  }
  
  for(int i=0;i<h;++i){
    bool ans=false;
    for(int j=0;j<w;++j){
      if(s[i][j]=='#'){
        break;
      }
      if(j==w-1){
        for(int k=0;k<w;++k)s[i][k]='0';
        ans=true;
      }
    }
    if(!ans){
      for(int j=0;j<w;++j){
        if(s[i][j]!='0')cout << s[i][j];
      } 
      cout << endl;
    }
  }

  return 0;
}