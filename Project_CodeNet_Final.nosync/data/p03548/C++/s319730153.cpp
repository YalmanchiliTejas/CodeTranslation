#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
  int x,y,z;
  cin >> x >> y >> z;
  x -= z;
  int t = y + z;
  cout << x / t << endl;
}
