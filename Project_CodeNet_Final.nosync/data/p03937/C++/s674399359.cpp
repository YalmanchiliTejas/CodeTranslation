#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int y,x; cin>>y>>x;
  char a[y][x];
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      cin>>a[i][j];
    }
  }
  
  int tmpY=0,tmpX=0;
  while(true){
    a[tmpY][tmpX]='.';
    if(a[tmpY+1][tmpX]=='#') tmpY=tmpY+1;
    else if(a[tmpY][tmpX+1]=='#') tmpX=tmpX+1;
    else break;
  }

  string ans="Possible";
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      if(a[i][j]=='#') ans="Impossible";
    }
  }
  cout<<ans<<endl;
  return 0;
}
