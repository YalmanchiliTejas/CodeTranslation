#include <cstdio>
#include <iostream>

using namespace std;


int main() {
  int s, t;
  int p, q, M, y;

  cin >> s >>t >> p >> q >> M >> y;

  cout << (t ^ s ^ y) << endl;

}

