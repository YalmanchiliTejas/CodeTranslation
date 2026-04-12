#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

#define TEST_ASSERT(msg, cond) do { if (cond) { cout << msg << " => pass" << endl;} else { cout << msg << " => failed" << endl;} } while(0)

using namespace std;

int main() {

  int x,y,z;
  cin >> x;
  cin >> y;
  cin >> z;

  int max = 0;
  for (int i = 1; i <= 1000000; ++i) {
	  if (x < (i*y + z*(i+1))) {
		  max = i - 1;
		  break;
	  }
  }

  cout << max << endl;

  return 0;
}
