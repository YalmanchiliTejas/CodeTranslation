#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <list>
using namespace std;
typedef unsigned long long u64;
typedef signed long long l64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  u64 n;
  cin >> n;
  list< u64 > b;
  for (u64 i = 0; i < n; ++i) {
    u64 a;
    cin >> a;
    if (i%2==0) b.push_front(a);
    else b.push_back(a);
  }
  if (n%2==0) b.reverse();
  for (u64 x : b) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
