#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
using namespace std;


int main(void) {

  int r,g,b;
  cin >> r >> g >> b;

  cout << ( (100*r + 10*g + b)%4 == 0 ? "YES" : "NO") << endl;

  return 0;
}
