#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
const double PI = acos(-1.0);
const long mod = 1000000007;
const long INF = 1e9 + 1;

int main() {
  int n,m,a[10][10];
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) a[i][j] = 0;
  }
  for(int i = 0; i < m; i++) {
    int x,y; cin >> x >> y;
    a[x][y] = 1; a[y][x] = 1;
  }

  vector<int> b;
  for(int i = 0; i < n; i++) b.push_back(i+1);
  int cnt = 0;
  do {
    bool flag = 0;
    for(int i = 0; i < n-1; i++) {
      if(a[b[i]][b[i+1]] == 1) flag = 1;
      else {
        flag = 0; break;
      }
    }
    if(flag) cnt++;
  } while(next_permutation(b.begin()+1,b.end()));

  cout << cnt << endl;
}