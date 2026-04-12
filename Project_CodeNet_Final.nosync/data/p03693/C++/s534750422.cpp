#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int n = b*10 + c;
  if(n % 4 == 0) cout << "YES\n";
  else cout << "NO\n";
}
