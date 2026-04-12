#include <iostream>

using namespace std;

int main(void){
  int n, sum;
  cin >> n;
  sum = n / 15;
  cout << 800 * n - 200 * sum << endl;
  return 0;
}