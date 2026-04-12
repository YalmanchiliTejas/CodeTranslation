#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  double X, Y, Z;
  cin >> X >> Y >> Z;
  for (int i=0; i<=(X-Z)/(Y+Z); i++) {
    if ((X-Y-2*Z)/(Y+Z)<i && i<=(X-Z)/(Y+Z)) {
      cout << i << endl;
    }
  }
}
