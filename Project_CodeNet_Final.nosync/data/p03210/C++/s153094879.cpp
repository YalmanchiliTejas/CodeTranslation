#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int A;
  cin >> A;
  if (A == 3 || A == 5 || A == 7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}