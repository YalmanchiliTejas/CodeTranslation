#include <iostream>
using namespace std;

int main(void) {
  int S, N;
  
  cin >> N;
  S = 800 * N - (N/15) * 200;
  cout << S << endl;

  return 0;
}