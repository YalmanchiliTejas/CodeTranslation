#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string str_out = "NO";
  if (n == 7 || n == 5 || n == 3) str_out = "YES";
  cout << str_out << endl;
}