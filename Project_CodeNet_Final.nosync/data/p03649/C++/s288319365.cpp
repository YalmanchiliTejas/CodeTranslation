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
  lint A[N];
  REP(i,N)cin>>A[i];
  lint ans=0;
  while(1){
    lint temp=0;
    REP(i,N){
      lint k=A[i]/N;
      temp+=k;
      A[i]%=N;
      REP(j,N){
        if(i==j)continue;
        A[j]+=k;
      }
    }
    // REP(i,N)cerr<<A[i]<<" ";
    // cerr<<endl;
    if(temp==0)break;
    ans+=temp;
  }

  cout<<ans<<endl;
  return 0;
}
