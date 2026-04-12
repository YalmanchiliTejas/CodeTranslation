#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int m,n,i,j,hantei;
  cin >> m >> n;
  char a[m][n];
  for(i=0;i<m;i++){
    hantei=0;
    for(j=0;j<n;j++){
      cin >> a[i][j];
      if(a[i][j]=='#'){
        hantei++;
      }
    }
    if(hantei==0){
      for(j=0;j<n;j++){
        a[i][j]=0;
      }
    }
  }
  for(i=0;i<n;i++){
    hantei=0;
    for(j=0;j<m;j++){
      if(a[j][i]=='#'){
        hantei++;
      }
    }
    if(hantei==0){
      for(j=0;j<m;j++){
        a[j][i]*=2;
      }
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(a[i][j]=='.'||a[i][j]=='#'){
        cout<<a[i][j];
      }
    }
    if(a[i][n-1]!=0){
      cout << endl;
    }
  }
}       