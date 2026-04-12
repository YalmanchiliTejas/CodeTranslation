#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int main() {
  int m;
  cin >> m;
  for (int z = 0; z < m; z++) {
    int money, year, n;
    int maxi = 0;
    cin >> money >> year >> n;
    for (int i = 0; i < n; i++) {
      int k;
      double r;
      int f;
      int p = money;
      cin >> k >> r >> f;
      int intre = 0;
      for (int j = 0; j < year; j++) {
	double d = p * r;
	if (k) {
	  p += (int)d;
	} else {
	  intre += d;
	}
	p -= f;
      }
      maxi = max(maxi, p + intre);
    }
    cout << maxi << endl;
  }
}