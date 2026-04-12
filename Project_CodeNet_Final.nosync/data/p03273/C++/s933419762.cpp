#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  char a[H][W];
  bool hf[H];
  REP(i,H)hf[i]=false;
  bool wf[W];
  REP(i,W)wf[i]=false;
  REP(i,H)REP(j,W){
    cin>>a[i][j];
    if(a[i][j]=='#'){
      hf[i]=true;
      wf[j]=true;
    }
  }
  REP(i,H){
    if(!hf[i])continue;
    REP(j,W){
      if(!wf[j])continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
  return 0;
}
