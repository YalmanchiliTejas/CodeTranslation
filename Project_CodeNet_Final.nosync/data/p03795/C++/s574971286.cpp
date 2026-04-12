#include <iostream>
using namespace std;

int main() {
  int N;
  int a;
  int b;

  cin >> N;
  
  a = N / 15;
  b = 800 * N - 200 * a;
  
  cout << b << endl;
}