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
  int N;
  string s;
  cin>>N;
  cin>>s;
  string t[4];
  t[0]="SS";
  t[1]="SW";
  t[2]="WS";
  t[3]="WW";
  FOR(i,1,N){
    REP(j,4){
      if((s[i]=='o')^(t[j][i]=='S')) t[j]+=(t[j][i-1]=='S'?'W':'S');
      else  t[j]+=(t[j][i-1]=='S'?'S':'W');
    }
  }
  // REP(i,4)cerr<<t[i]<<endl;
  REP(i,4){
    bool f=(t[i][0]==t[i][N])and(((s[0]=='o')^(t[i][0]=='S'))==(t[i][1]!=t[i][N-1]));
    if(!f)continue;
    cout<<t[i].substr(0,N)<<endl;
    return 0;
  }
  cout<<"-1"<<endl;
  return 0;
}
