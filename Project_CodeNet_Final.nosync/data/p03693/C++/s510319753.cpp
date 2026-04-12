#include<iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int number = a * 100 + b * 10 + c;

  if (number % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
