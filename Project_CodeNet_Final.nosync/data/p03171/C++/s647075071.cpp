//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
#define forr(i,m,n) for (int i=(m); i<=(n); i++)
#define forall(it,p) for (auto it = p.begin(); it != p.end(); ++it)
#define DBG 1

#define MAXN 3001
int a[MAXN];
long b[MAXN][MAXN][2];

int main() {
  int n;
  cin >> n;
  forr(i,0,n-1)
    cin >> a[i];
  forr(i,0,n-1) {
    b[i][i][0] = a[i];
    b[i][i][1] = -a[i];
  }
  forr(d,1,n-1)
    forr(i,0,n-1-d) {
      int j = i+d;
      b[i][j][0] = max( a[i]+b[i+1][j][1], b[i][j-1][1]+a[j]);
      b[i][j][1] = min(-a[i]+b[i+1][j][0], b[i][j-1][0]-a[j]);
    }
  cout << b[0][n-1][0];

}
