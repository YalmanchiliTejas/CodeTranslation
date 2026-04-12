#include <cmath>
#include <iostream>

using namespace std;

int main() {
  char chs[3];
  for (int i = 0; i < 3; i++) { cin >> chs[i]; }
  cout << (chs[0] == chs[1] && chs[1] == chs[2] ? "No" : "Yes") << endl;
}

