#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int N, T, E;
  while(cin>>N>>T>>E){
    vector<int> x(N); 
    REP(i, N) cin>>x[i];
    int ans = -2;
    REP(i, N){
      int nx = 0;
      while(nx <= T + E){
        if(abs(T-nx) <= E)ans = i;
        nx += x[i];
      }
    }
    cout<<ans + 1<<endl;
  }
  return 0;
}