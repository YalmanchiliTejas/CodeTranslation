#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> P;

int main() {
  P a[101];
  int n=0;
  while(1) {
    scanf("%d%*c%d",&a[n].second,&a[n].first);
    if(a[n].first==0 && a[n].second==0) break;
    n++;
  }
  sort(a,a+n,greater<P> ());
  map<int,int> m;
  int rank=1;
  m[a[0].second]=rank;
  for(int i=1; i<n; i++) {
    if(a[i].first!=a[i-1].first) rank++;
    m[a[i].second]=rank;
  }
  int x;
  while(cin >> x) {
    cout << m[x] << endl;
  }
  return 0;
}
