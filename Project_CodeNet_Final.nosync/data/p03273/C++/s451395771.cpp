#include <iostream>

using namespace std;

int H,W;
int k=0;
char a[110][110]={};

int main(){
  cin >> H >> W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<H;i++){
    k=0;
    for(int j=0;j<W;j++){
      if(a[i][j]!='#'){
        k++;
      }
    }
    if(k==W){
      for(int I=i;I<H-1;I++){
        for(int j=0;j<W;j++){
          a[I][j]=a[I+1][j];
        }
      }
      H=H-1;
      i--;
    }
  }

  for(int i=0;i<W;i++){
    k=0;
    for(int j=0;j<H;j++){
      if(a[j][i]!='#'){
        k++;
      }
    }
    if(k==H){
      for(int I=i;I<W-1;I++){
        for(int j=0;j<H;j++){
          a[j][I]=a[j][I+1];
        }
      }
      W=W-1;
      i--;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << a[i][j];
    }
    cout << endl;
  }
}
