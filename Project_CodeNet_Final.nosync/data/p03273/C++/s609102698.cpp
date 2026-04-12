#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  char s[101][101];
  bool atx[101], aty[101];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        atx[i]=true;
        aty[j]=true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(atx[i]){
      for(int j=0;j<w;j++){
        if(aty[j]){
          cout<<s[i][j];
        }
      }
      cout<<endl;
    }
  }
}
    
      
    
    
    