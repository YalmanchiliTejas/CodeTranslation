#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void push(vector<vector<int>>& tb, int i, int j) {
  int d[2] = {0,1};
  REP(k,2)REP(l,2){
    int ni=i+d[k];
    int nj=j+d[l];
    if(tb[ni][nj] != 0) {
      ++tb[ni][nj];
      if(tb[ni][nj] == 5) tb[ni][nj] = 1;
    }
  }
}

int score(const vector<vector<int>>& tb) {
  int sum = 0;
  REP(i,5)REP(j,5){
    switch(tb[i][j]){
      case 2:
      sum += 60;
      break;
      case 3:
      sum += 70;
      break;
      case 4:
      sum += 80;
      break;
    }
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  REP(i,n){
    vector<vector<int>> tb(5,vector<int>(5));
    REP(j,5)REP(k,5) cin >> tb[j][k];
    vector<vector<vector<int>>> dp(256);
    REP(j,256){
      auto cp = tb;
      REP(k,4){
        int l=(j>>(2*k))%4;
        REP(m,l)push(cp,0,k);
      }
      dp[j] = cp;
    }
    REP(j,3) {
      vector<vector<vector<int>>> tmp(256);
      REP(k,256){
        int maxv=-1;
        vector<vector<int>> mxt;
        for(auto cp:dp){
          REP(l,4){
            int m=(k>>(2*l))%4;
            REP(o,m)push(cp,j+1,l);
          }
          int scr = score(cp);
          if(maxv < scr) {
            maxv = scr;
            mxt = cp;
          }
        }
        tmp[k] = mxt;
      }
      swap(tmp, dp);
    }
    int maxv = 0;
    for(auto t:dp){
      maxv=max(maxv, score(t));
    }
    cout << maxv << endl;
  }
  return 0;
}