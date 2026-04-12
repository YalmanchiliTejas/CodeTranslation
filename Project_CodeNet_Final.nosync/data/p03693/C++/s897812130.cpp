#include <iostream>

using namespace std;

int main()
{
  int n=0, a;
  
  for (int i = 0; i < 3; i++) {
    cin >> a;
    n = 10 * n + a;
  }
  
  cout << ((n % 4 == 0) ? "YES" : "NO") << endl;
}