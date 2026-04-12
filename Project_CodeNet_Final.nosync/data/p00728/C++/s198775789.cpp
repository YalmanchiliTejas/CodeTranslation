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
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};



main(){
  int n;
  while(cin>>n,n){
    vector<int> in;
    int sum=0;
    rep(i,n){
      int t;
      cin>>t;
      sum+=t;
      in.pb(t);
    }
    sort(ALL(in));
    sum-=in[0]+in.back();
    cout<<sum/(n-2)<<endl;
    
    
  }
}