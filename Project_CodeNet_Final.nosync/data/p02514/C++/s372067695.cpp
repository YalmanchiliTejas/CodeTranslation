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
static const double EPS = 1e-8;
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

int w,h;
vector<pair<int,PI > > G[3000];

int s2i(const string &in){
  stringstream ss(in);
  int ret;
  ss>>ret;
  return ret;
}

void solve(){
  rep(i,3000)G[i].clear();
  string tt;
  PI go;
  int maxv=0;
  rep(i,h)rep(j,w){
    cin>>tt;
    if(tt=="S")G[0].pb(mp(0,mp(i,j)));
    else if(tt==".")continue;
    else if(tt!="G"){
      int v=s2i(tt);
      maxv=max(v,maxv);
      G[v].pb(mp(1<<28,mp(i,j)));
    }else{
      go=mp(i,j);
    }
  }
  G[maxv+1].pb(mp(1<<28,go));
  for(int i=0;i<=maxv;++i){
    FOR(it1,G[i]){
      FOR(it2,G[i+1]){
        it2->F=min(it2->F,
                   it1->F+abs(it1->S.F-it2->S.F)+abs(it1->S.S-it2->S.S));
      }
    }
  }
  cout<<G[maxv+1][0].F<<endl;
}

main(){
  while(cin>>w>>h,w)solve();
}