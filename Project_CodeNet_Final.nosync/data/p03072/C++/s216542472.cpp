#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (max <= a) {
      sum++;
      //cout << a << ' ' << sum << ' ' << max << endl;
      max = a;
    }
  }
  cout << sum << endl;
  return 0;
}