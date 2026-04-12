#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  int a=h+w-1,b=0;
  char g[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> g[i][j];
      if(g[i][j]=='#')b++;
    }
  }
  if(a==b)cout << "Possible";
  else cout << "Impossible";
}