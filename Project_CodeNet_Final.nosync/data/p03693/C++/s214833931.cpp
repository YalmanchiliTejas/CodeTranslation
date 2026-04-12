#include <iostream>
#include <string>
using namespace std;

int main() {
  string r, g, b; cin >> r >> g >> b;
  cout << (stoi(r+g+b) % 4 == 0 ? "YES" : "NO") << endl;
}