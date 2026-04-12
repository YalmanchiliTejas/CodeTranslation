#include <iostream>
#include <vector>
using namespace std;
int main(){
  int h,w;
  int i,j;
  cin >> h >> w;
  vector<vector<char>> d(h, vector<char>(w));
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin >> d[i][j];
    }
  }
  vector<bool> a(h,false);
  vector<bool> b(w,false);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(d[i][j] == '#'){
        a[i]=true;
        b[j]=true;
      }
    }
  }
  for(i=0;i<h;i++){
    if(a[i]==false) continue;
    for(j=0;j<w;j++){
      if(b[j]==false) continue;
      else cout << d[i][j];
    }
    cout << "\n";
  }
  return 0;
}