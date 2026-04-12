#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j,h,w,k=0,l=0,z=0;
  cin >> h;
  cin >> w;
  int m[h],n[w];
  char a[h][w];
  for(i=0;i<h;i++){
    for (j=0;j<w;j++) {
      cin >> a[i][j];
      m[i]=9999999999;
      n[j]=9999999999;
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++) {
      if(a[i][j]=='#'){
        k=1;
        break;
      }
    }
    if(k==1){
      k=0;
      continue;
    }
    else{
      m[l]=i;
      l++;
    }
  }
  l=0;
  for(i=0;i<w;i++){
    for (j=0;j<h;j++) {
      if(a[j][i]=='#'){
        k=2;
        break;
      }
    }
    if(k==2){
      k=0;
      continue;
    }
    else{
      n[l]=i;
      l++;
    }
  }
  l=0;
  int q=0;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(i==m[l]||j==n[z]){
        if(j==n[z]){
          z++;
        }
        q++;
        continue;
      }
      else{
        cout << a[i][j];
      }
    }
    z=0;
    if(q==w){
      l++;
    }
    else{
      cout << endl;
    }
    q=0;
  }
}
