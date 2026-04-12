#include <string>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
  int wqwq;
  cin >> wqwq;
  string x;
  cin >> x;
    int a;
  cin >> a;
  int n = x.size();
  for (int i =0; i < n; i++) {
    if (x[i] == x[a - 1])
      cout << x[a - 1];
    else
      cout << '*';
  }
}