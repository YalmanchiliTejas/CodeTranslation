#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using VL=vector<ll>;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const long long INF =  999999999;

ll N,a[3010];
ll dp[3010][3010];

int main(){
  cin >>N;
  REP(i,N){
    cin >>a[i];
  }
  REP(i,N+1){
    REP(j,N+1)dp[i][j]=0;
  }
  for(int len=1;len<=N;len++){
    for(int l=0;l<=N-len;l++){
      int r=l+len;
      if((N-len)%2==0){
        dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
      }else{
        dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
      }

    }
  }
  cout <<dp[0][N]<<endl;
}
