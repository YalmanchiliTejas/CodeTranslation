#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  const char* result = "No";
  if ((S[0] != S[1]) || (S[1] != S[2])) {
    result = "Yes";
  }
  cout << result << endl;
  return 0;
}
