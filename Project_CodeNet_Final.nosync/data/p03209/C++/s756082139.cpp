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
lint a[51],b[51];
lint count(lint L,lint X){
  // cerr<<"called "<<L<<" "<<X<<endl;
  if(L==0)return X;
  if(X==a[L])return b[L];
  else if(X>a[L-1]+2)return b[L-1]+1+count(L-1,X-a[L-1]-2);
  else if(X==a[L-1]+2)return b[L-1]+1;
  else if(X==a[L-1]+1)return b[L-1];
  else if(X>1)return count(L-1,X-1);
  else return 0;
}

int main(){
  lint N,X;
  cin>>N>>X;
  a[0]=1;
  b[0]=1;
  FOR(i,1,51){
    a[i]=a[i-1]*2+3;
    b[i]=b[i-1]*2+1;
  }
  cout<<count(N,X)<<endl;
  return 0;
}
