#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w,cnt=0;
  cin >> h >> w;
  char a[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]=='#') cnt++;
    }
  }
  if(cnt!=h+w-1) cout << "Impossible" << endl;
  else cout << "Possible" << endl;
}