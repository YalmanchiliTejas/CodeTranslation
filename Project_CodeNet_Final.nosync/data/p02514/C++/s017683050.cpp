#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

bool hoge(int x,int y,int z) {
  return x&&x%3==0&&y%3==2&&z%3==2; 
}

int main() {
  int a,b,c,d,e,f;
  while(cin>>a>>b>>c>>d>>e>>f,a||b||c||d||e||f) {
    int x=a+d,y=b+e,z=c+f;
    int res = x/3+y/3+z/3;
    res += min(x%3, min(y%3, z%3));
    if (hoge(x,y,z)||hoge(y,z,x)||hoge(z,x,y))
      res++;
    cout << res<< endl;
  }
}