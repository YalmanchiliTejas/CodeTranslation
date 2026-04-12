#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string msg;
  msg = (n == m) ? "Yes" : "No";
  cout << msg << endl;
}
