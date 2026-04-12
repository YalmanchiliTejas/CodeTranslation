#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

int main(void)
{
  int a, b;
  cin >> a >> b;
  if (a < b) cout << "a < b" << "\n";
  else if (a == b) cout << "a == b" << "\n";
  else cout << "a > b" << "\n";
  return 0;
}