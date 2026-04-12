#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <stdio.h>
using namespace std;
using ll =long long;

int main (void) {
  int H,W;
  cin >> H >>W;
  char A[H][W];
  int count=0;
  for (int i=0; i<H; i++) {
      for (int j=0; j<W; j++) {
        cin >> A[i][j];
        if (A[i][j]=='#'){
          count++;
        }
      }
  }
  puts((count==H+W-1)?"Possible":"Impossible");
}