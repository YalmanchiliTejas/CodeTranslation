#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int m[3] = {1,2,3};
int c(int n){
  return (7-n);
}
int main(void){
  int N;
  while(cin>>N){
    REP(i,3) m[i]=i+1;
    int count=0;
    if(N==0) break;
    string str;
    REP(i,N){
      int nm[3];
      REP(i,3)nm[i]=m[i];
      cin>>str;
        if(str== "North"){
          nm[0]=m[1];
          nm[1]=c(m[0]);
          }
        if(str== "East"){
          nm[0]=c(m[2]);
          nm[2]=m[0];
          }
        if(str== "West"){
          nm[0]=m[2];
          nm[2]=c(m[0]);
          }
        if(str== "South"){
          nm[0]=c(m[1]);
          nm[1]=m[0];
          }
        if(str== "Right"){
          nm[1]=m[2];
          nm[2]=c(m[1]);
          }
        if(str== "Left"){
          nm[1]=c(m[2]);
          nm[2]=m[1];
          }
      REP(i,3)m[i]=nm[i];
      count+=m[0];
    }
    cout<<count+1<<endl;
  }
  return 0;
}