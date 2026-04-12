#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for(int i=0; i<N; ++i) cin >> X[i];
  int cnt = 0;
  int mx=0;
  for(int i=0; i<N; ++i){
    if(X[i] >= mx) ++cnt;
    mx= max(mx, X[i]);
  }
  cout << cnt << endl;
}