#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, x, y;
  cin >> n;
  x = 800 * n;
  y = 200 * (n / 15);
  cout << x - y << endl;
  return 0;
}