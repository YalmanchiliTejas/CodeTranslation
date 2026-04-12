#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))

using namespace std;
int h,w;
vector<int> v1;
vector<int> v2;
char ban[150][150];

int main(){
  cin >> h >> w;
  REP(i,h){
    REP(j,w){
      cin >> ban[i][j];
    }
  }
  REP(i,h){
    int f = 0;
    REP(j,w){
      if(ban[i][j]=='#') f = 1;
    }
    if(f==1) v1.push_back(i);
  }
  REP(j,w){
    int f = 0;
    REP(i,h){
      if(ban[i][j]=='#') f = 1;
    }
    if(f==1) v2.push_back(j);
  }
  REP(i,v1.size()){
    REP(j,v2.size()){
      cout << ban[v1[i]][v2[j]];
    }
    cout << endl;
  }
  return 0;
}
