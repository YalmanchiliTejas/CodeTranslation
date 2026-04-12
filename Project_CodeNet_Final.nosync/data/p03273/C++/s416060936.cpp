#include <bits/stdc++.h>
using namespace std;

void init(char t[],int W);
int main(){
  int H,W;
  int i,j;
  cin>>H>>W;
  char a[H][W+1];
  bool flag_h[H];
  bool flag_w[W];
  for(i=0;i<H;i++){
    cin>>a[i];
    flag_h[i]=false;
  }
  for(i=0;i<W;i++){
    flag_w[i]=false;
  }
  printf("\n");

  for(i=0;i<H;i++){
    if(a[i][0]=='.'){
      for(j=0;j<W;j++){
        if(a[i][j]=='#'){
            flag_h[i]=true;
            break;
        }
      }
    }else flag_h[i]=true;
  }

  for(i=0;i<W;i++){
    if(a[0][i]=='.'){
      for(j=0;j<H;j++){
        if(a[j][i]=='#'){
          flag_w[i]=true;
        }
      }
    }else flag_w[i]=true;
  }
  
  for(i=0;i<H;i++){
    if(flag_h[i]){
      for(j=0;j<W;j++){
        if(flag_w[j]){
          cout<<a[i][j];
        }
      }
      cout<<endl;
    }
  }

  return 0;
}
