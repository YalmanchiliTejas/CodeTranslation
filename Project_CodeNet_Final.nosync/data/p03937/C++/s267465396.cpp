#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<(x)<<endl
#define fi first
#define se second

#define INF 2147483600

vector<string> vec;
int h,w;

bool dfs(int x, int y){
  if(x==h-1 && y==w-1) return true;
  if(vec[x][y]=='.') return false;
  // migi
  if(y+1<w && vec[x][y+1]=='#' && dfs(x, y+1)) return true;
  else if(x+1<h && vec[x+1][y]=='#' && dfs(x+1,y)) return true;
  return false;
}

int main(){
  cin>>h>>w;
  vec.resize(h);
  rep(i,h) cin>>vec[i];

  int cnt=0;
  rep(i,h) rep(j,w) if(vec[i][j]=='#') cnt++;

  if(cnt!=h+w-1 || !dfs(0,0)){
    cout<<"Impossible"<<endl;
  } else {
    cout<<"Possible"<<endl;
  }

  return 0;
}
