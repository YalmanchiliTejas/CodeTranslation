#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define f first
#define s second
#define mp make_pair

using namespace std;

int main(){
  typedef pair<int, pair<int, int> > date;

  int n;
  while(cin >> n, n){
    vector<date> d(n);

    REP(i, n) cin >> d[i].f >> d[i].s.f >> d[i].s.s;
    sort(d.begin(), d.end());

    REP(i, n) printf("%04d %02d %02d\n", d[i].f, d[i].s.f, d[i].s.s);
  }
  return 0;
}