#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  int X;
  cin >> X;
  if (X % 2 && X % 8 - 1) {
	  cout << "YES" << endl;
	} else {
	  cout << "NO" << endl;
	}
  return 0;
}
