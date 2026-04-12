#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int A, B, C, X, Y, Z;
  cin >> A >> B >> C >> X >>Y;
  int ans = 0;

  if(X > Y) Z = (X - Y)*A;
  else Z = (Y - X)*B;

  if(A+B < 2*C){
    cout << A*X+B*Y << endl;
  } else {
    int a = max(X, Y)*2*C;
    int b = min(X, Y)*2*C + Z;
    if(a > b) cout << b << endl;
    else cout << a << endl;
  }

  return 0;
}

