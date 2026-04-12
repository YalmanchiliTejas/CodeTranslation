#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  char ma[111][111];
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>ma[i][j];

  int x[111]={},y[111]={};
  for(int i=0;i<h;i++){
    
    int f=1;
    for(int j=0;j<w;j++){
      if(ma[i][j]=='#'){
	f=0;
	break;
      }
    }
    y[i]=f;
  }

  for(int j=0;j<w;j++){
    int f=1;
    for(int i=0;i<h;i++){
      if(ma[i][j]=='#'){
	f=0;
	break;
      }
    }
    x[j]=f;
  }

  for(int i=0;i<h;i++){
    int f=0;
    for(int j=0;j<w;j++){
      if(y[i]||x[j])continue;
      cout<<ma[i][j];
      f=1;
    }
    if(f)cout<<endl;
  }
  return 0;
}
