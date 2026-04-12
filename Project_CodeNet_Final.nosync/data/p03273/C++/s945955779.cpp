#include <bits/stdc++.h>
using namespace std;
int main(){
  int h, w, i, j;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (i=0;i<h;i++){
    for (j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  vector<bool> b(h),c(w);
  for (i=0;i<h;i++){
    for (j=0;j<w;j++){
      if (a[i][j]=='#'){
        b[i]=true;
      }
    }
  }
  for (j=0;j<w;j++){
    for (i=0;i<h;i++){
      if (a[i][j]=='#'){
        c[j]=true;
      }
    }
  }
  for (i=0;i<h;i++){
    if(b[i]){
      for(j=0;j<w;j++){
        if(c[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}