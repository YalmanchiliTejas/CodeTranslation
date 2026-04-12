#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int mod = 1e9+7;
long long int inf = 1e18;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  cout << x / (y+z) << endl;

  return 0;
}

//
