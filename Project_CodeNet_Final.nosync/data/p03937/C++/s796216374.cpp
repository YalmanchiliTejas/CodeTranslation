#include <iostream>
#include <vector>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<bool>>chk(h+2, vector<bool>(w+2, false));
  vector<vector<char>>a(h+2, vector<char>(w+2, '.'));
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++)cin >> a[i][j];
  int x=1, y=1;
  chk[x][y]=true;
  for(int i=0; i<h+w; i++){
    if(i%2==0)while(a[x+1][y]=='#'){x++; chk[x][y]=true;}
    if(i%2==0)while(a[x][y+1]=='#'){y++; chk[x][y]=true;}
  }
  if(!(x==h && y==w)){cout << "Impossible"; return 0;}
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++)if(a[i][j]=='#' && (!chk[i][j])){cout << "Impossible"; return 0;}
  cout << "Possible";
  return 0;
}