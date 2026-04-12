/**
 * author: moririn_cocoa       
**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main(void) {
  
  int r;
  int g;
  int b;
  
  cin >> r;
  cin >> g;
  cin >> b;
  
  if ( ( 100 * r + 10 * g + b ) % 4 == 0 ) {
    
    cout << "YES" << endl;
  }
  
  else {
    
    cout << "NO" << endl;
  }
  
  return 0;
}