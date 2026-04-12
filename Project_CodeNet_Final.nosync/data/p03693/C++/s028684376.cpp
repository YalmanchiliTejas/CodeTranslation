#include <iostream>
using namespace std;
int main() {
 int r, g, b;
 cin >> r >> g >> b;
 int result = r * 100 + g * 10 + b;
 if (result % 4)
  cout << "NO";
 else
   cout << "YES";
 return 0;
}