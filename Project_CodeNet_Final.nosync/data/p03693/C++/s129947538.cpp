#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <bitset>
 
using namespace std;
 
 
int main()
{
  int r, g, b;

  cin >> r >> g >> b;

  if ((r*100+g*10+b)%4) {
	  cout << "NO" << endl;
  } else {
	  cout << "YES" << endl;
  }

  return 0;
}