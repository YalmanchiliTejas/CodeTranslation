#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int x,y,z;
  cin >> x >> y >> z;

  for(int i = 1; ; i++) { 
    if(x < ((i+1)*z + i*y)) {
      cout << i-1 << endl;
      return 0;
    }
  }
}