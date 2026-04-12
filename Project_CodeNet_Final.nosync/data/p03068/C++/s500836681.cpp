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
#include <set>
#include <random>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  k--;
  for (int i = 0; i < n; i++) {
	  if (s[i] != s[k]) {
		  s[i] = '*';
		}
	}
  cout << s << endl;
  return 0;
}
