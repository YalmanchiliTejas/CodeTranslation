#include<iostream>
using namespace std;
int main(){
  int h,w,i,j;cin >> h >> w;bool white;
  char a[h][w];
  for(i=0;i<h;i++){
    for(j=0;j<w;j++) cin >> a[i][j];
  }
  for(j=0;j<w;j++){
    white = true;
    for(i=0;i<h;i++){
      if(a[i][j]=='#') white = false;
    }
    if(white){
      for(i=0;i<h;i++) a[i][j] = 'x';
    }
  }
  for(i=0;i<h;i++){
    white = true;
    for(j=0;j<w;j++){
      if(a[i][j]=='#') white = false;
    }
    if(!white){
      for(j=0;j<w;j++){
        if(a[i][j]!='x') cout << a[i][j];
      }
      cout << endl;
    }
  }
}