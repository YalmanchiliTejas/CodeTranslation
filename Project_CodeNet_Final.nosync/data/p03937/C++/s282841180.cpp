#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  char a[h][w];
  int s=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
      if(a[i][j]=='#') s++;
    }
  }
  if(a[0][0]=='.'||a[h-1][w-1]=='.'){
    cout<<"Impossible"<<endl;
    return 0;
  }
  
  int x=0,y=0,flag=0,ss=1;
  while(1){
    if(x+1<h&&y+1<w){
      if(a[x+1][y]=='#'&&a[x][y+1]=='.') x++;
      else if(a[x+1][y]=='.'&&a[x][y+1]=='#') y++;
      else{
        cout<<"Impossible"<<endl;
        return 0;
      }
    }else if(x+1<h){
      if(a[x+1][y]=='#') x++;
      else{
        cout<<"Impossible"<<endl;
        return 0;
      }
    }else if(y+1<w){
      if(a[x][y+1]=='#') y++;
      else{
        cout<<"Impossible"<<endl;
        return 0;
      }
    }else{
      flag=1;
      break;
    }
    ss++;
  }
  if(flag&&s==ss) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}
