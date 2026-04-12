#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz size()
#define pb push_back
#define mp make_pair
#define ALL(X) (X).begin(),(X).end()

using namespace std;

const int INF = 1000000000;
const double eps = 1e-8;

int main(void) {
  int m;cin>>m;
  REP(i,m){
    double A;
    int y,n;
    cin>>A>>y>>n;
    double maxx = 0.0;
    REP(j,n){
      int tf,fee;
      double index;
      cin>>tf>>index>>fee;
      double cA = A;
      if(tf == 0){
        int r = 0;
        REP(k,y){
          r += (int)(cA*index);
          cA -= fee;
        }
        if(maxx < cA+r){
          maxx=cA+r;
        }
      }else{
        REP(k,y){
          cA += (int)(cA*index) - fee;
        }
        if(maxx < cA){
          maxx=cA;
        }
      }
    }
    cout<<(int)maxx<<endl;
  }
  return 0;
}