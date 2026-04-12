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
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=0;
  if(2*C<A+B){
    int Z=min(X,Y);
    ans+=2*C*Z;
    X-=Z;
    Y-=Z;
  }
  if(2*C<A){
    ans+=2*C*X;
    X=0;
  }
  if(2*C<B){
    ans+=2*C*Y;
    Y=0;
  }
  ans+=A*X+B*Y;
  cout<<ans<<endl;
  return 0;
}
