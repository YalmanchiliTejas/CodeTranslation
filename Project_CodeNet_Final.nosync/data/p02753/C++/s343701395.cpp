#include <bits/stdc++.h>
using namespace std;

string Str;
string message = "Yes";

int main() {
  cin >> Str;
  if (Str[0] == Str[1] && Str[1] == Str[2]) {
    message = "No";
  }
  cout << message << endl;
  return 0;
}
