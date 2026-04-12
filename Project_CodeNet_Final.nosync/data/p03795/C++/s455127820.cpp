#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int x = 800 * N;
  int b = N / 15;
  int y = 200 * b;
  
  cout << x - y;
  
}