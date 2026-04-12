#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int light[10][10];
bool solve(int n){
  int ans[10][10];
  int rslt[10];
  REP(i,10){
    if(i==0) REP(j,10)ans[i][j] = (n>>j&1);
    else REP(j,10) ans[i][j] = rslt[j];
    REP(j,10) rslt[j] = light[i][j];
    REP(j,10){
      if(j-1>=0)rslt[j] ^= ans[i][j-1];
      rslt[j] ^= ans[i][j];
      if(j+1<10)rslt[j] ^= ans[i][j+1];
      if(i-1>=0)rslt[j] ^= ans[i-1][j];
    }
  }
  bool right = true;
  REP(j,10) if(rslt[j]) right = false;
  if(right){
    REP(y,10){
      REP(x,10){
        if(x) cout<<" ";
        cout<<ans[y][x];
      }
      cout<<endl;
    }
  }
  return right;
}


int main(void){
  int N;
  cin>>N;
  while(N--){
    REP(y,10)REP(x,10) cin>>light[y][x];
    REP(i,1<<10) if(solve(i)) break;
  }
  return 0;
}