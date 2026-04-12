#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int i,j,k,n,m;
string s;

int main() {
  int x,y,z;cin >> x >> y >> z;
  int out = x / (y+z);
  if (x % (y + z) < z) --out;
  cout << out << endl; 
  return 0;
}
