#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;

  int b;
  b = n / 15;

  cout << n * 800 - b * 200 << endl;

  return 0;
}
