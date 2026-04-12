#include <bits/stdc++.h>
using namespace std;
int h,w,x,y,a[8][8];
string s[8];
int main(){
  cin>>h>>w;
  for(int i=0;i<h;++i)cin>>s[i];
  a[0][0]++;
  for(int i=0;i<h+w-2;++i){
    if(s[x][y+1]=='#'){
      y++;
      a[x][y]++;
    }else if(s[x+1][y]=='#'){
      x++;
      a[x][y]++;
    }else{
      cout << "Impossible" << endl;
      return 0;
    }
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if((s[i][j]=='.'&&a[i][j]==1)||(s[i][j]=='#'&&a[i][j]==0)){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
  return 0;
}