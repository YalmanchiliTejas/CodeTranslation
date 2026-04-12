#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define sym cout<<"-----------"<<endl;
#define ll long long
#define P pair<int,int>
#define mk make_pair
#define en endl
#define RE return 0
#define int ll


// B

int grid[105][105];

signed main(){
  int h,w;
  cin>>h>>w;
  for(int i=1; i<=h; i++) for(int j=1; j<=w; j++){
    char ch; cin>>ch;
    if(ch=='.') grid[i][j]=0;
    else grid[i][j]=1;
  }

  set<int> yoko;
  for(int i=1; i<=h; i++){
    bool black=false;
    for(int j=1; j<=w; j++){
      if(grid[i][j]==1) black=true;
    }
    if(black) continue;
    else yoko.insert(i);
  }
  set<int> tate;
  for(int j=1; j<=w; j++){
    bool black=false;
    for(int i=1; i<=h; i++){
      if(grid[i][j]==1) black=true;
    }
    if(black) continue;
    tate.insert(j);
  }

  for(int i=1; i<=h; i++){
    if(yoko.find(i)!=yoko.end()) continue;
    for(int j=1; j<=w; j++){
      if(tate.find(j)!=tate.end()) continue;
      if(grid[i][j]==1) cout<<'#';
      else cout<<'.';
    }
    cout<<en;
  }
}