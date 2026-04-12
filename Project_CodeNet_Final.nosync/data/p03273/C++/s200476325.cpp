#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  int h,w;
  char a[200][200];
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++)
      cin >> a[i][j];
  }
  int num_h[200],m = 0;
  for(int i = 0; i < h; i++) {
    bool flag = 0;
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '.') flag = 1;
      else {
        flag = 0; break;
      }
    }
    if(flag) {
      num_h[m] = i; m++;
    }
  }
  int num_w[200],n = 0;
  for(int j = 0; j < w; j++) {
    bool flag = 0;
    for(int i = 0; i < h; i++) {
      if(a[i][j] == '.') flag = 1;
      else {
        flag = 0; break;
      }
    }
    if(flag) {
      num_w[n] = j; n++;
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      for(int x = 0; x < m; x++) {
        if(i == num_h[x]) goto Exit1;
      }
      for(int y = 0; y < n; y++) {
        if(j == num_w[y]) goto Exit2;
      }
      cout << a[i][j];
      Exit2: ;
    }
    cout << endl;
    Exit1: ;
  }
}