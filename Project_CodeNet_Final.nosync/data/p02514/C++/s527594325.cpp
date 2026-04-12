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
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <list>
#include <ctime>
#include <numeric>
using namespace std;
static const double EPS = 1e-6;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
const double pi=acos(-1);
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};

main(){
  while(true){
    ll in[3]={0};
    rep(i,6){
      int t;
      cin>>t;
      in[i%3]+=t;
    }
    sort(in,in+3);
    if(in[2]==0)break;
    ll ans=0;
    rep(j,4){
      if(in[0]<j)break;
      ll tans=0;
      tans+=in[0]-j;
      tans+=(in[1]-tans)/3+(in[2]-tans)/3;
      ans=max(tans,ans);
    }
    cout<<ans<<endl;
  }
}