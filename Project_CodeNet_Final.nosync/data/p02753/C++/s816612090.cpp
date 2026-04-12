#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int A = 0;
  if (S[0] == 'A')
    ++A;
  if (S[1] == 'A')
    ++A;
  if (S[2] == 'A')
    ++A;
  if (A == 1 || A == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
