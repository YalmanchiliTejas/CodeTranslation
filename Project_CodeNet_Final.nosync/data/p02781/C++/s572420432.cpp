#include <iostream>
#include <cmath>
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
  string N;
  lint K;
  cin>>N>>K;
  lint L=N.size();
  lint n[L];
  REP(i,L)n[i]=N[i]-'0';
  lint dp0[L+1][4];
  lint dp1[L+1][4];
  REP(i,L+1)REP(j,4){
    dp0[i][j]=0;
    dp1[i][j]=0;
  }
  dp1[0][0]=1;
  FOR(i,1,L+1){
    FOR(j,1,4)dp0[i][j]+=9*dp0[i-1][j-1];
    REP(j,4)dp0[i][j]+=dp0[i-1][j];
    if(n[i-1]==0){
      REP(j,4)dp1[i][j]=dp1[i-1][j];
    }else{
      FOR(j,1,4)dp1[i][j]=dp1[i-1][j-1];
      REP(j,4)dp0[i][j]+=dp1[i-1][j];
      FOR(j,1,4)dp0[i][j]+=(n[i-1]-1)*dp1[i-1][j-1];
    }
  }
  // REP(i,L+1){
  //   REP(j,4)cerr<<dp0[i][j]<<" "<<dp1[i][j]<<"||";
  //   cerr<<endl;
  // }
  cout<<dp0[L][K]+dp1[L][K]<<endl;
  return 0;
}
