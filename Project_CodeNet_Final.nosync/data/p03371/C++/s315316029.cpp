#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back

int a, b, c, x, y;

int main()
{
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  int ans = a*x + b*y;
  for (int i = 2*max(x, y); i >= 0; i -= 2)
    {
      ans = min(ans, a*max(0, x-i/2) + b*max(0, y-i/2) + i*c);
    }
  printf("%d\n", ans);
}


