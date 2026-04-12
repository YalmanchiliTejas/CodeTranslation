#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <stack>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int c[N][N];
  REP(i,N){
    REP(j,N)c[i][j]=0;
  }
  REP(i,M){
    int a,b;
    cin>>a>>b;
    c[a-1][b-1]=1;
    c[b-1][a-1]=1;
  }
  stack<pair<int,vector<int> > > s;
  vector<int> v;
  s.push(make_pair(0,v));
  int ans=0;
  while(!s.empty()){
    pair<int,vector<int> > p=s.top();
    s.pop();
    int pi=p.first;
    vector<int> pv=p.second;
    pv.push_back(pi);
    if(pv.size()==N)ans++;
    REP(i,N){
      if(c[pi][i] and find(ALL(pv),i)==pv.end()){
        s.push(make_pair(i,pv));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}