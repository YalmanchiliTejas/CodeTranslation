#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  cout << (x - z) / (y + z) << endl;
  return 0;
}