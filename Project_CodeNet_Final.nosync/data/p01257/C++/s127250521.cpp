#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int v[1<<10];
int dp[100001];

int main() {
  int n,m;
  while(cin>>n>>m,n||m) {
    int a[n];
    REP(i,n) cin >> a[i];
    REP(S,1<<n) {
      int s=0;
      REP(i,n) if (S>>i&1) s+=a[i];
      v[S]=s;
    }
    REP(i,m+1)dp[i]=INF;
    dp[0] = 0;
    for (int S=1; S<(1<<n); ++S) {
      for (int i=0; i+v[S]<=m; ++i)
        dp[i+v[S]] = min(dp[i+v[S]], dp[i]+1);
    }
    cout << dp[m] << endl;
  }
}