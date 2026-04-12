#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  vector<vector<char>> data(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      cin>>data[i][j];
  }
  vector<int>tate(w);
  vector<int>yoko(h);
  
  for(int i=0;i<h;i++){
    int countw=0;
    for(int j=0;j<w;j++){
      if(data[i][j]=='#')
        countw++;
    }
    if(countw==0)
      yoko[i]++;
  }
  
  for(int i=0;i<w;i++){
    int counth=0;
    if(data[0][i]=='.'){
      for(int j=0;j<h;j++){
        if(data[j][i]=='.')
          counth++;
      }
      if(counth==h){
        tate[i]++;
      }
    }
  }
  
  for(int i=0;i<h;i++){
    bool t=true;
    for(int j=0;j<w;j++){
      if(yoko[i]==1){
        t=false;
        break;
      }
      if(tate[j]==1)
        continue;
      cout<<data[i][j];
    }
    if(t)
      cout<<endl;
  }
}