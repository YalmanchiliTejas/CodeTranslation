#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int r, g, b; cin >> r >> g >> b;
  string result;
  if ((g*10+b)%4==0) result = "YES"; 
  else result = "NO";
  cout << result << endl;
  return 0;
}