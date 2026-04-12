#include<bits/stdc++.h>
using namespace std;
int h,w;
char a[105][105];
int t[105],y[105];
int main(){
  cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      if(a[i][j]=='#'){
        y[i]=1;
      }
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(a[i][j]=='#'){
        t[j]=1;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(y[i]==1){
      for(int j=0;j<w;j++){
        if(t[j]==1){
          cout<<a[i][j];
        }
      }
      cout<<endl;
    }
  }
  return 0;
}