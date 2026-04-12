#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>
#include <string>
#include <sstream>
using namespace std;


int main(){
  int r, g, b; cin >> r >> g >> b;
  stringstream ss;
  ss << r << g << b;
  int n;
  ss >> n;
  if(n%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}
