#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  while(cin>>n){
    if(n==0) break;
    int mid = (n-1)/2;
    int grid[15][15] = {0};
    int x=mid; int y=mid+1;
    grid[y][x] = 1;
    for(int i=2; i<=n*n; i++){
      x++,y++;
      if(x<0) x = n-1;
      if(x>=n) x = 0;
      if(y>=n) y = 0;
      while(grid[y][x]!=0){
        x--,y++;
        if(x<0) x = n-1;
        if(x>=n) x = 0;
        if(y>=n) y = 0;
      }
      grid[y][x] = i;
    }
    REP(y,n){
      REP(x,n){
        printf("%4d",grid[y][x]);
      }
      cout<<endl;
    }
  }
  return 0;
}