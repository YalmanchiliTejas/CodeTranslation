#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string> map;
  for(int y=0;y<H;y++){
    string s;
    cin>>s;
    int x;
    for(x=0;x<W;x++) if(s[x]!='.') break;
    if(x!=W) map.push_back(s);
  }
  vector<int> removes(W,0);
  for(int x=0;x<W;x++){
    int y;
    for(y=0;y<map.size();y++){
      if(map[y][x]!='.') break;
    }
    if(y==map.size())removes[x]=1;
  }
  for(int y=0;y<map.size();y++){
  	for(int x=0;x<W;x++){
      if(removes[x]==1) continue;
      cout<<map[y][x];
    }
    cout<<"\n";
  }
  return 0;
}