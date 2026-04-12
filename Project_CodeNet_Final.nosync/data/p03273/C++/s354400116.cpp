#include <iostream>

using namespace std;

int main(){
  int i,j,k,n,h,w,x=0,y=0;
  bool ch=true;
  cin >> h >> w;
  char a[h][w],b[h][w],c[h][w];
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  for(i=0;i<h;i++){
    ch = true;
    for(j=0;j<w;j++){
      if(a[i][j]!='.'){
        for(k=0;k<w;k++){
          b[x][k]=a[i][k];
        }
        x++;
        break;
      }
    }
  }
  for(i=0;i<w;i++){
    ch = true;
    for(j=0;j<x;j++){
      if(b[j][i]!='.'){
        for(k=0;k<x;k++){
          c[k][y]=b[k][i];
        }
        y++;
        break;
      }
    }
  }
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      cout << c[i][j];
    }
    cout << endl;
  }
  return 0;
}
