#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  char a[h][w];
  int row[h]={}, col[w]={};
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> a[i][j];
      if(a[i][j]=='#') {
        row[i] = 1;
        col[j] = 1;
      }    
    }
  }
  for(int i=0; i<h; i++) {
    if(row[i]==1) {
      for(int j=0; j<w; j++) {
        if(col[j]==1) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }  
  return 0;
}