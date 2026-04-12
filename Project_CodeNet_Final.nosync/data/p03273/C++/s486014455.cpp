#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> a(H,vector<char>(W)) ;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>a.at(i).at(j);
    }
  }
  vector<bool> yoko(H);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(a.at(i).at(j)=='#')break;
      if(j==W-1) yoko.at(i)=1;
    }
  }
   vector<bool> tate(W);
  for(int i=0;i<W;i++){
    for(int j=0;j<H;j++){
      if(a.at(j).at(i)=='#')break;
      if(j==H-1) tate.at(i)=1;
    }
  }
  for(int i=0;i<H;i++){
    if(yoko.at(i))continue;
    for(int j=0;j<W;j++){
      if(tate.at(j))continue;
      cout<<a.at(i).at(j);
    }
    cout<<endl;
  }
}