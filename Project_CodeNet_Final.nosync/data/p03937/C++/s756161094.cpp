#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  for(int i=0;i<h;i++){
    cin>>a[i];
  }
  int cnt=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)if(a[i][j]=='#')cnt++;
  }
  queue<int> x;
  queue<int> y;
  x.push(0);
  y.push(0);
  while(x.empty()!=1){
    int nx=x.front();
    int ny=y.front();
    //cout<<nx<<" "<<ny<<endl;
    x.pop();
    y.pop();
    if(nx==w-1&&ny==h-1&&cnt==w+h-1){
      cout<<"Possible"<<endl;
      return 0;
    }
    //cout<<a[ny][nx+1]<<" "<<a[ny+1][nx]<<endl;
    if(nx+1<w&&a[ny][nx+1]=='#'){
      x.push(nx+1);
      y.push(ny);
    }
    if(ny+1<h&&a[ny+1][nx]=='#'){
      x.push(nx);
      y.push(ny+1);
    }
  }
  cout<<"Impossible"<<endl;
  return 0;
}
