#include <bits/stdc++.h>
using namespace std;
int main(){
int h,w;
  cin >> h >> w;
  char a[h][w];
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  bool ans=true;
  for (int i=0;i<h-1;i++){
    for (int j=0;j<w-1;j++){
      if (a[i+1][j]=='#' && a[i][j+1]=='#')ans=false;
    }
  }
  if (ans)cout << "Possible" <<endl;
    else cout << "Impossible" << endl;
}
