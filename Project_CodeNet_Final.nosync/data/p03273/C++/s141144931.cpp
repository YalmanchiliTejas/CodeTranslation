#include <iostream>
#include <string>

using namespace std;

int H,W;
int k=0;
char a[110][110]={};

int solve(int A,int B){
  for(int i=0;i<A;i++){
    k=0;
    for(int j=0;j<B;j++){
      if(a[i][j]!='#'){
        k++;
      }
    }
    cout << k << endl;
    if(k==B){
      for(int I=i;I<A-1;I++){
        for(int j=0;j<B;j++){
          a[I][j]=a[I+1][j];
        }
      }
      A=A-1;
    }
  }
  return A;
}

int main(){
  cin >> H >> W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a[i][j];
    }
  }
  //H=solve(H,W);
  for(int i=0;i<H;i++){
    k=0;
    for(int j=0;j<W;j++){
      if(a[i][j]!='#'){
        k++;
      }
    }
    //cout << k << endl;
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

/*
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << a[i][j];
    }
    cout << endl;
  }
  */


  //cout << H << W << endl;
  //W=solve(W,H);
  for(int i=0;i<W;i++){
    k=0;
    for(int j=0;j<H;j++){
      if(a[j][i]!='#'){
        k++;
      }
    }
    //cout << k << endl;
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
