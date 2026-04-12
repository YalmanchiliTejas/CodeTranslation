#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int answer = 0;
  while (true) {
    int need = (answer + 1) * Y + (answer + 2) * Z;
    if (need > X) break;
    ++answer;
  }
  cout << answer << endl;
  return 0;
}