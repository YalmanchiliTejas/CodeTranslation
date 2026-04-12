#include<iostream>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  char a[h][w];
  int i,j;
  bool hf[h]={},wf[w]={};
  
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(a[i][j]=='#'){
        hf[i]=1;
        break;
      }
    }
  }
  
  for(i=0;i<w;i++){
    for(j=0;j<h;j++){
      if(a[j][i]=='#'){
        wf[i]=1;
        break;
      }
    }
  }

  for(i=0;i<h;i++){
    if(hf[i]==1){
      for(j=0;j<w;j++){
        if(wf[j]==1){
        cout<<a[i][j];
        }
      }
      cout<<endl;
    }
  }
  
  return 0;
}