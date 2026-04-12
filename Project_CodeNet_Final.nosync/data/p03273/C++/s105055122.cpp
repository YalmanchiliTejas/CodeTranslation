
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define ll long long
using namespace std;

int main(){
 // cout<<12<<endl<<endl<<endl;
  int W,H;
  cin>>H>>W;
  char masume[H+1][W+1];
  for (int i=0;i<H; i++) {
    string s;
    cin>>s;
    for (int j=0; j<W; j++) {
      masume[i][j] = s[j];
    }
  }
  
  // i want to get space
  
  //cout<<endl;
  
  set <int> tate,yoko;
  //tate
  for(int i=0;i<H;i++){
    bool flag=true;
    for(int j=0;j<W;j++){
      if(masume[i][j]=='#') flag=false;
    }
    if( flag) {tate.insert(i);}//cout<<i<<endl;}
  }
  
  //yoko
  for(int i=0;i<W;i++){
    bool flag=true;
    for(int j=0;j<H;j++){
      if(masume[j][i]=='#') flag=false;
    }
    if( flag) {yoko.insert(i);}//cout<<i<<endl;}
  }
  
  
  
  for(int i=0;i<H;i++){
    bool g=false;
    for(int j=0;j<W;j++){
      if(tate.find(i) != tate.end() or yoko.find(j) != yoko.end()){continue;}//cout<<1<<endl;continue;}
      cout<<masume[i][j];g=true;
    }
    if(not g) continue;
    cout<<endl;
  }
  
  return 0;
}

