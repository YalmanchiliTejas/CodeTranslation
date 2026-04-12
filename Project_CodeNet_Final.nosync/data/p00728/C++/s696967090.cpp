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
  while(1){
    int n;
    cin>>n;
    if(n==0)break;
    vector<int> a(n);
    REP(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int sum = 0;
    FOR(i,1,n-1)sum+=a[i];
    cout<<sum/(n-2)<<endl;
  }
  return 0;
}