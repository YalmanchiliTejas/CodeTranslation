#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
  int n;
  while(cin>>n, n) {
    int ba[n][n];
    int x = n/2;
    int y = x;
    y++;

    memset(ba, 0, sizeof(ba));
    int i = 1;
    while (i<=n*n) {
     
      if (x<0) {
        x = n - 1;
        continue;
      } else if (x>=n) {
        x = 0;
        continue;
      } else if (y>=n) {
        y = 0;
        continue;
      } else if(ba[x][y] != 0) {
        x--;
        y++;
        continue;
      } else {
        ba[x][y] = i++;
        x++;
        y++;
      }
    }
    REP(i,n) {
      REP(j,n) {
        printf("%4d", ba[j][i]);
      }
      cout << endl;
    }
  }
}