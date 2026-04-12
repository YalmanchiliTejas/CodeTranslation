
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main(void) {
  string s;
  cin >> s;
  if(s == "AAA" || s == "BBB") {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
