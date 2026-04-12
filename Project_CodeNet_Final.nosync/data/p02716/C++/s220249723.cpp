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
  lint S=0,T=0,U=0;
  REP(i,N/2){
    lint S1,T1,U1;
    S1=S+A[2*i+1];
    S1=max(S1,T+A[2*i+1]);
    T1=T+A[2*i];
    U1=U+A[2*i];
    U1=max(U1,S);
    U1=max(U1,T);
    S=S1;T=T1;U=U1;
  }
  if(N%2==1){
    U+=A[N-1];
    cout<<max(S,max(T,U))<<endl;
  }else{
    cout<<max(S,T)<<endl;
  }
  return 0;
}
