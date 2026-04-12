#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N, z;
  cin >> N;

  z = 800 * N - 200 * (N / 15);
  cout << z << endl;

  return 0;
}
