#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >>H>>W;
  char a[H][W];
  bool letu[W];
  bool gyou[H];
  for (int i=0;i<W;i++){
    letu[i]=0;
  }
  for (int i=0;i<H;i++){
    gyou[i]=0;
  }
  
  for (int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a[i][j];
      if (a[i][j]=='#'){
        letu[j]=1;
        gyou[i]=1;
      }
    }
  }
  
  for (int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if((letu[j]==1)&&(gyou[i]==1)){
        cout<<a[i][j];
      }
    }
    if (gyou[i]==1){
      cout<<endl;
    }
  }
  return 0;
}


  
  