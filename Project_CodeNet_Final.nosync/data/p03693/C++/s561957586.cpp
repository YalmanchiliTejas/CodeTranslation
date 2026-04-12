#include<iostream>
#include<string>
using namespace std;

int main() {
  int r, g, b;
  string res = "NO";

  cin >> r >> g >> b;

  if ((r*100 + g*10 + b)%4 == 0)
    res = "YES";

  cout << res << endl;

  return 0;

}

