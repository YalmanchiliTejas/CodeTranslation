 #include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 1 << 28;

#define D(x) cout << x << endl;
#define d(x) cout << x;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int main() {
  int n;
  cin >> n;
  int x = n * 800;
  int y = n / 15;
  y *= 200;

  D(x - y);
  
  return 0;
}
