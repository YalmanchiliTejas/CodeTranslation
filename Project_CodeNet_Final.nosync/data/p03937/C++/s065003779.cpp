#include<iostream>
using  namespace std;
int main(){
  int h,w,cnt =0;cin >> h >> w;char c[10][10];
  for(int i = 0; i < h;i++){
    for(int j = 0;j < w;j++){
      cin >> c[i][j];
      if(c[i][j] == '#') cnt++;
    }
  }
  if(cnt == h+ w - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}