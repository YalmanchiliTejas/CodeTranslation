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

#define FOR(i,a,b) for(lint i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  lint N,X,M;
  cin>>N>>X>>M;
  lint D[M];
  vector<lint> S;
  S.push_back(X);
  REP(i,M)D[i]=-1;
  D[X]=0;
  lint X_prev;
  bool skipped=false;
  FOR(i,1,N){
    X_prev=X;
    X=(X*X)%M;
    if(D[X]<0 or skipped){
      D[X]=i;
      S.push_back(S.back()+X);
    }else{
      lint l=(i-D[X]);
      lint c=(N-i)/l;
      lint s=(S.back()-(D[X]!=0?S[D[X]-1]:0));
      i+=l*c-1;
      cerr<<"l="<<l<<" c="<<c<<" s="<<s<<" i="<<i<<endl;
      S.push_back(S.back()+s*c);
      X=X_prev;
      skipped=true;
    }
  }
  cout<<S.back()<<endl;
  return 0;
}
