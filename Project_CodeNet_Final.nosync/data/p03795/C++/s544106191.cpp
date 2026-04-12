#include <iostream>
using namespace std;
typedef unsigned long long u64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << n*800 - (n/15)*200 << endl;
  return 0;
}
