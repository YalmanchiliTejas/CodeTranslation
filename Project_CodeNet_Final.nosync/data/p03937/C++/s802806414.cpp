#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int H,W;
vector<string> vs;

bool dfs(int y, int x, int nokori)
{
  if(nokori==0) return true;
  bool ret = false;
  if(x+1 < W && vs[y][x+1] == '#') ret |= dfs(y,x+1,nokori-1);
  if(y+1 < H && vs[y+1][x] == '#') ret |= dfs(y+1,x,nokori-1);
  return ret;
}

int main(){
  cin>>H>>W;
  int cnt = 0;
  FOR(y,0,H){
    string s;
    cin>>s;
    vs.push_back(s);
    FOR(x,0,s.length())
    {
      if(s[x]=='#') cnt++;
    }
  }
  if(cnt!=H+W-1)
  {
    cout << "Impossible" << endl;
    return 0;
  }
  if(dfs(0,0,H+W-2))
  {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
