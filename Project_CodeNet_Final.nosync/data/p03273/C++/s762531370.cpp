#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char> (w));
  vector<bool> b(h),c(w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){
         b[i]=true;
      }
    }
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(a[i][j]=='#'){
         c[j]=true;
      }
    }
  }
  for(int i=0;i<h;i++){
    if(b[i]){
    for(int j=0;j<w;j++){
      if(c[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }
}