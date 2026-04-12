#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int tmp = 0;
  tmp = a * 100 + b * 10 + c;
  if(tmp % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
