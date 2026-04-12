#include <iostream>
#include <queue>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  string map[h];
  int num=0;
  for(int i=0;i<h;i++){
    cin>>map[i];
    for(int j=0;j<w;j++)
      if(map[i][j]=='#') num++;
  }
  queue<int> qx,qy,cnt;
  qx.push(0); qy.push(0); cnt.push(1);
  while(!qx.empty()){
    int x=qx.front(); int y=qy.front(); int c=cnt.front();
    qx.pop(); qy.pop(); cnt.pop();
    if(x==w-1&&y==h-1&&c==num){
      cout<<"Possible"<<endl; return 0;
    }
    if(x<w-1&&map[y][x+1]=='#'){
      qx.push(x+1); qy.push(y); cnt.push(c+1);
    } else if(y<h-1&&map[y+1][x]=='#'){
      qx.push(x); qy.push(y+1); cnt.push(c+1);
    }
  }
  cout<<"Impossible"<<endl;
}
