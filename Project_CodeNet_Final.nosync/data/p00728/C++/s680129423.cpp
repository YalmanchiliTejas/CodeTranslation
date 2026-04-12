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
#include <numeric>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  while(cin>>n){
    if(n==0) break;
    vector<int> a(n);
    REP(i,n)cin>>a[i];
    int s = accumulate(a.begin(),a.end(),0)- *min_element(a.begin(),a.end())
      - *max_element(a.begin(),a.end());
    cout<<s/(n-2)<<endl;
  }
  return 0;
}