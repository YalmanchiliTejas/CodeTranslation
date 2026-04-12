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
  cin>>N;
  int m=0;
  int ans=0;
  REP(i,N){
    int H;
    cin>>H;
    if(H>=m)ans++;
    m=max(m,H);
  }
  cout<<ans<<endl;
  return 0;
}
