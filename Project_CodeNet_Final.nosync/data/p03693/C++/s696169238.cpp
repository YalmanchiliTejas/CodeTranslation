#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
int a,b,c;
  cin >> a >>b >>c;
  int d = a*100 + b*10+c;
  if (d %4 == 0) cout <<"YES" << endl;
  else cout << "NO" << endl;
}