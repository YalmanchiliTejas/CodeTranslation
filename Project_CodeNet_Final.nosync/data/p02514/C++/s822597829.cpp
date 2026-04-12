#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Point{
public:
  int y,m,d;
  bool operator < (const Point &p) const{
    if(p.y == y && p.m == m) return d < p.d;
    else if(p.y == y) return m < p.m;
    else return y < p.y;
  }
};

int main(){
  int i,j,k,n,ans;
  while(cin >> n){
    if(n == 0) break;
    Point p[101];
    for(i=0;i<n;i++) cin >> p[i].y >> p[i].m >> p[i].d;
    sort(p,p+n);
    for(i=0;i<n;i++) printf("%04d %02d %02d\n",p[i].y,p[i].m,p[i].d);

  }
  return 0;
}