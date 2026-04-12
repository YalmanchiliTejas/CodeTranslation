#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int ca, cb, cab, a, b;
  cin >> ca >> cb >> cab >> a >> b;

  cab *= 2;
  int res = a*ca + b*cb;
  res = min(res, a*ca+b*cab);
  res = min(res, b*cb+a*cab);
  res = min(res, a*cab+max(0, b-a)*cb);
  res = min(res, b*cab+max(0, a-b)*ca);

  cout << res << endl;
  return 0;
}
