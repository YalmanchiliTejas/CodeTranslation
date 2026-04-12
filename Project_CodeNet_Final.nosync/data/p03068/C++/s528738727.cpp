#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <math.h>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, k, r;
  string s;

  cin >> n >> s >> k;

  r = s[k - 1];

  for (int i = 0; i < n; i++) {
    if(s[i]!=r)
		s[i]='*';
  }

  cout << s << endl;

  return 0;
}
