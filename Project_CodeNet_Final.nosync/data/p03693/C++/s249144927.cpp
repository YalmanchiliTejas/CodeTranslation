#include <iostream>
using namespace std;
typedef unsigned long long u64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, g, b;
  cin >> r >> g >> b;
  int a = r * 100 + g * 10 + b;
  if (a % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

