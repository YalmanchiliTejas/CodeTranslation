#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
static const int MAX = 200000;

int main()
{
  int n[2];
  cin >> n[0] >> n[1];
  if(n[0] == n[1])cout << "Yes" <<endl;
  else cout << "No"<<endl;
  return 0;
}
