#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

int main(){
  ll h,w;
  cin >> h >> w;
  char a[h][w];
  REP(i,h)REP(j,w) cin >> a[i][j];
  bool blank_row[h];
  bool blank_col[w];
  fill(blank_col,blank_col+w,true);
  fill(blank_row,blank_row+h,true);
  REP(i,h){
    REP(j,w){
      if(a[i][j]=='#') blank_row[i] = false;
    }
  }
  REP(j,w){
    REP(i,h){
      if(a[i][j]=='#') blank_col[j] = false;
    }
  }
  REP(i,h){
    REP(j,w){
      if(!blank_row[i]&&!blank_col[j]) cout << a[i][j];
    }
    if(!blank_row[i]) cout << endl;
  }
  return 0;
}
