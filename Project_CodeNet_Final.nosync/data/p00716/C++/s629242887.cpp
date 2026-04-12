#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int m;
  cin>>m;
  while(m--){
    int money,year,n,ans=0;
    cin>>money>>year>>n;
    while(n--){
      int mymoney = money;
      int risoku,tesuu,risi=0;
      double ritu;
      cin>>risoku>>ritu>>tesuu;
      REP(i,year){
        if(risoku){
          risi += (mymoney+risi)*ritu;
        }else{
          risi += mymoney*ritu;
        }
        mymoney-=tesuu;
      }
      ans = max(ans, mymoney + risi);
    }
    cout<<ans<<endl;
  }
  return 0;
}