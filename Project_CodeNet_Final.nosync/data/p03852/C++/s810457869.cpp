#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define ll long long
#define INF (1 << 30)
#define INFLL (1LL << 60)

#define FOR(i,a,b) for(ll i = (a);i<(b);i++)
#define REP(i,a) FOR(i,0,(a))
#define MP make_pair

int main() {
  char c;
  cin >> c;

  if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }

  return 0;
}
