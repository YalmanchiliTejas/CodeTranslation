#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

#define pii pair<int,int>

int main() {
  int a,b;
  vector<pii> v;
  while(true) {
    scanf("%d,%d\n",&a,&b);
    if (a==0&&b==0) break;
    v.push_back(pii(b,a));
  }
  sort(ALL(v),greater<pii>());
  int c = v[0].first;
  int p = 1;
  map<int,int> x;
  FOR(i,v) {
    if ((*i).first<c) {
      p++;
      c = (*i).first;
    }
    //   printf("%d,%d, %d\n",(*i).first, (*i).second, p);
    x[(*i).second] = p;
  }
  int n;
  while(cin>>n)
    cout << x[n] << endl;

}