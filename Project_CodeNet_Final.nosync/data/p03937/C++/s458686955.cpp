#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

string field[10];


int main(){
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  rep(i,H){
    cin >> field[i];
  }

  bool flg = true;
  field[0][0]='@';
  while(field[H-1][W-1]=='#'){
    bool check = false;
    rep(i,H){
      rep(j,W){
        if(field[i][j]=='@'){
          int cnt = 0;
          if(i+1<H && field[i+1][j]=='#'){
            field[i+1][j]='@';
            cnt++;
            check = true;
          }
          if(j+1<W && field[i][j+1]=='#'){
            field[i][j+1]='@';
            cnt++;
            check = true;
          }
          if(cnt==2) flg = false;
        }
      }
    }
    if(!check) flg = false;
    if(!flg) break;
  }

  rep(i,H){
    rep(j,W){
      if(field[i][j]=='#') flg = false;
    }
  }
  
  if(flg){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  
  return 0;
}

